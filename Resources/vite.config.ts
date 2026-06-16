import { defineConfig } from "vite";
import { resolve } from "path";

export default defineConfig({
  build: {
    lib: {
      // Define the entry point for your TypeScript code
      entry: {
        game: resolve(__dirname, "Src/Main.ts"),
        cocos_lib: resolve(__dirname, "Script/jsb.ts"),
      },
      // The global variable name for your library when used in a script tag
      name: "SS",
      // The output filename formats
      fileName: (format) => `ss.${format}.js`,
      // Formats to generate: es = ES modules, umd = Universal Module Definition
      formats: ["es"],
    },
    sourcemap: true, // Optional: generates source maps for easier debugging
    minify: "esbuild", // Optional: minifies output code
  },
});
