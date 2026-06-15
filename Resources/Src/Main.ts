console.log("Hello from test.js!");
console.log(
  "This is a test script to verify that the JavaScript engine is working correctly.",
);
console.log(
  "If you see this message, it means that the script has been executed successfully.",
);
// Test cc.Configuration class
const config = cc.Configuration?.getInstance();
if (config) {
  console.log("Configuration instance created: " + config);
  console.log("Max texture size: " + config.getMaxTextureSize());
  console.log("Supports PVRTC: " + config.supportsPVRTC());
  console.log("Supports NPOT: " + config.supportsNPOT());
} else {
  console.error("Failed to create Configuration instance.");
}

const g_resources: string[] = [];

class HelloWorldLayer extends cc.Layer {
  sprite: cc.Sprite | null = null;
  constructor() {
    //////////////////////////////
    // 1. super init first
    super();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    // ask the window size
    var size = cc.winSize;

    /////////////////////////////
    // 3. add your codes below...
    // add a label shows "Hello World"
    // create and initialize a label
    var helloLabel = new cc.LabelTTF("Hello ccccccc World", "Arial", 38);
    // position the label on the center of the screen
    helloLabel.x = size.width / 2;
    helloLabel.y = size.height / 2 + 200;
    // add the label as a child to this layer
    this.addChild(helloLabel, 5);

    // add "HelloWorld" splash screen"
    this.sprite = new cc.Sprite("res/HelloWorld.png");
    this.sprite.attr({
      x: size.width / 2,
      y: size.height / 2,
    });
    this.addChild(this.sprite, 0);
  }
}

class HelloWorldScene extends cc.Scene {
  onEnter() {
    super.onEnter();
    const layer = new HelloWorldLayer();
    this.addChild(layer);
  }
}

cc.game.onStart = function () {
  const sys = cc.sys;
  if (!sys.isNative && document.getElementById("cocosLoading")) {
    //If referenced loading.js, please remove it
    document.body.removeChild(document.getElementById("cocosLoading")!);
  }

  // Pass true to enable retina display, on Android disabled by default to improve performance
  cc.view.enableRetina(sys.os === sys.OS_IOS ? true : false);

  // Disable auto full screen on baidu and wechat, you might also want to eliminate sys.BROWSER_TYPE_MOBILE_QQ
  if (
    sys.isMobile &&
    sys.browserType !== sys.BROWSER_TYPE_BAIDU &&
    sys.browserType !== sys.BROWSER_TYPE_WECHAT
  ) {
    cc.view.enableAutoFullScreen(true);
  }

  // Adjust viewport meta
  cc.view.adjustViewPort(true);

  // Uncomment the following line to set a fixed orientation for your game
  // cc.view.setOrientation(cc.ORIENTATION_PORTRAIT);

  // Setup the resolution policy and design resolution size
  cc.view.setDesignResolutionSize(960, 640, cc.ResolutionPolicy.SHOW_ALL);

  // The game will be resized when browser size change
  cc.view.resizeWithBrowserSize(true);

  //load resources
  cc.LoaderScene.preload(
    g_resources,
    function () {
      cc.director.runScene(new HelloWorldScene());
    },
    this as any,
  );
};
cc.game.run();
