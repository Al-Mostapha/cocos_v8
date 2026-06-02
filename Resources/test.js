console.log("Hello from test.js!");
console.log("This is a test script to verify that the JavaScript engine is working correctly.");
console.log("If you see this message, it means that the script has been executed successfully.");
// Test cc.Configuration class 
const config = cc.Configuration?.getInstance();
if(config) {
    console.log("Configuration instance created: " + config);
    console.log("Max texture size: " + config.getMaxTextureSize());
    console.log("Supports PVRTC: " + config.supportsPVRTC());
    console.log("Supports NPOT: " + config.supportsNPOT());
}else{
    console.error("Failed to create Configuration instance.");
}