import { defineConfig } from "vite";
import { resolve } from "path";

export default defineConfig({
  build: {
    lib: {
      entry: resolve(__dirname, "Src/Main.ts"),
      name: "SS",
      fileName: () => "game.js",
      formats: ["es"],
    },
    rollupOptions: {
      output: {
        globals: {
          cc: "cc",
        },
      },
    },
    sourcemap: true, // Optional: generates source maps for easier debugging
    minify: "esbuild", // Optional: minifies output code
  },
});
