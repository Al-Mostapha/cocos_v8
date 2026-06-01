#include "JsbUtils.h"
#include "JsbAllCocos.hpp"
#include "JsbCommon.hpp"
#include "JsbNode.hpp"
#include "ScriptEngine.hpp"
#include "JsbScene.hpp"
#include "JsbNodeSpecial.hpp"
#include "UI/JsbWidget.hpp"
#include "UI/JsbButton.hpp"
#include "UI/JsbText.hpp"

void register_all_cocos2dx(v8::Isolate *isolate, v8::Local<v8::Object> obj)
{
  v8::HandleScope scope(isolate);
  // Get the ns
  // JS::RootedObject ns(cx);
  v8::Local<v8::Object> ns;
  // get_or_create_js_obj(cx, obj, "cc", &ns);
  JsbUtils::GetOrCreateJsObject(isolate, obj, "cc", &ns);
  js_register_cocos2dx_Configuration(isolate, ns);
  js_register_cocos2dx_Device(isolate, ns);
  js_register_cocos2dx_Node(isolate, ns);
  js_register_cocos2dx_Scene(isolate, ns);
  js_register_cocos2dx_ProtectedNode(isolate, ns);
  js_register_cocos2dx_ui_Widget(isolate, ns);
  js_register_cocos2dx_ui_Button(isolate, ns);
  js_register_cocos2dx_ui_Text(isolate, ns);
}