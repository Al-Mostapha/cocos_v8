declare namespace jsb {
  function loadRemoteImg(
    url: string,
    callback: (suc: boolean, img: any) => void,
  ): void;

  // let urlRegExp: RegExp;
  function garbageCollect(): void;
  function dumpRoot(): void;

  const AudioEngine: any;
}
