import { defineConfig } from "vite";
import { resolve } from "path";

export default defineConfig({
  plugins: [
    {
      // ROOT CAUSE
      // TypeScript compiles `namespace cc {}` to an IIFE pattern:
      //   var cc;
      //   (function(cc){ ... })(cc ||= {});
      //
      // Rollup bundles multiple modules into one flat scope and renames each
      // module's `var cc` to a unique name (t, r, i, …) to avoid collisions.
      // After renaming, the IIFE becomes:
      //   var t;
      //   (function(e){ ... })(t ||= {});        ← t is {}  NOT the C++ global
      //
      // Inside the IIFE TypeScript emits two kinds of `cc.X` references:
      //   • exports of the current block  → compiled to IIFE-parameter access
      //   • things from merged blocks      → compiled to outer-var access (t)
      //
      // Both therefore need to reference globalThis.cc.
      //
      // FIX (applied per-module, before Rollup renames anything):
      // Change the IIFE call expression from
      //   (cc ||= {})
      // to
      //   (cc = globalThis.cc || (globalThis.cc = {}))
      //
      // After Rollup renames cc → t this becomes:
      //   (t = globalThis.cc || (globalThis.cc = {}))
      // which sets the outer var AND passes the C++ object to the IIFE parameter,
      // so every reference inside the IIFE hits the real C++ globalThis.cc.
      name: "cc-global-namespace",
      transform(code, id) {
        if (id.includes("node_modules")) return null;

        const next = code
          // esbuild shorthand (es2021+): (cc ||= {})
          .replace(/\(cc\s*\|\|=\s*\{\}\)/g, "(cc = globalThis.cc || (globalThis.cc = {}))")
          // plain TypeScript output: (cc || (cc = {}))
          .replace(
            /\(cc\s*\|\|\s*\(cc\s*=\s*\{\}\)\)/g,
            "(cc = globalThis.cc || (globalThis.cc = {}))",
          )
          // same two patterns for ccui
          .replace(
            /\(ccui\s*\|\|=\s*\{\}\)/g,
            "(ccui = globalThis.ccui || (globalThis.ccui = {}))",
          )
          .replace(
            /\(ccui\s*\|\|\s*\(ccui\s*=\s*\{\}\)\)/g,
            "(ccui = globalThis.ccui || (globalThis.ccui = {}))",
          );

        return next !== code ? { code: next, map: null } : null;
      },
    },
  ],
  build: {
    lib: {
      entry: resolve(__dirname, "Src/Main.ts"),
      name: "SS",
      fileName: () => "game.js",
      formats: ["es"],
    },
    rollupOptions: {
      output: {
        // The banner's `var cc` is the one Rollup resolves free-variable `cc`
        // references (e.g. in Main.ts) to, ensuring game code also operates on
        // globalThis.cc rather than an isolated empty object.
        banner:
          "var cc = globalThis.cc || (globalThis.cc = {});\n" +
          "var ccui = globalThis.ccui || (globalThis.ccui = {});",
        globals: {
          cc: "cc",
          ccui: "ccui",
        },
      },
    },
    sourcemap: true,
  },
});
