import { defineConfig } from "vite";
import { resolve } from "path";

export default defineConfig({
  build: {
    lib: {
      // Define the entry point for your TypeScript code
      entry: resolve(__dirname, "src/main.ts"),
      // The global variable name for your library when used in a script tag
      name: "MyJSCoreLib",
      // The output filename formats
      fileName: (format) => `my-js-core-lib.${format}.js`,
      // Formats to generate: es = ES modules, umd = Universal Module Definition
      formats: ["es", "umd"],
    },
    sourcemap: true, // Optional: generates source maps for easier debugging
    minify: "esbuild", // Optional: minifies output code
  },
});
