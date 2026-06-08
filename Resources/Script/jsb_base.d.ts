declare namespace cc {
  require: (path: string, callback?: Function) => void;

  class Point {
    x: number;
    y: number;
  }
  class Size{
    width: number;
    height: number;
  }
}

declare const cc: typeof import("cc");
declare const jsb: typeof import("cc");
