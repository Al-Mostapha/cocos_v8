#include <iostream>
#include <string>
#include <memory>
#include "v8.h"
#include "libplatform/libplatform.h"

class V8HelloWorld {
private:
    v8::Platform* platform;
    v8::Isolate* isolate;

public:
    V8HelloWorld() : platform(nullptr), isolate(nullptr) {
        // Initialize V8
        v8::V8::InitializeICU();
        platform = v8::platform::NewDefaultPlatform_Without_Stl(0, v8::platform::IdleTaskSupport::kDisabled, v8::platform::InProcessStackDumping::kDisabled, nullptr, v8::platform::PriorityMode::kDontApply);
        v8::V8::InitializePlatform(platform);
        v8::V8::Initialize();

        // Create a new isolate
        v8::Isolate::CreateParams create_params;
        create_params.array_buffer_allocator = v8::ArrayBuffer::Allocator::NewDefaultAllocator();
        isolate = v8::Isolate::New(create_params);
    }

    ~V8HelloWorld() {
        // Cleanup
        if (isolate) {
            isolate->Dispose();
        }
        v8::V8::Dispose();
        v8::V8::DisposePlatform();
        if (platform) {
            delete platform;
        }
    }

    void runHelloWorld() {
        // Create isolate scope
        v8::Isolate::Scope isolate_scope(isolate);

        // Create a stack-allocated handle scope
        v8::HandleScope handle_scope(isolate);

        // Create a new context
        v8::Local<v8::Context> context = v8::Context::New(isolate);

        // Enter the context for compiling and running the hello world script
        v8::Context::Scope context_scope(context);

        std::cout << "=== V8 Hello World Examples ===\n\n";

        // Example 1: Simple Hello World
        runSimpleExample(context);

        // Example 2: Variables and Functions
        runVariableExample(context);

        // Example 3: Objects and Arrays
        runObjectExample(context);

        // Example 4: Error Handling
        runErrorExample(context);

        // Example 5: C++ Function Integration
        runCppFunctionExample(context);
    }

private:
    void runSimpleExample(v8::Local<v8::Context> context) {
        std::cout << "1. Simple Hello World:\n";

        // Create a string containing the JavaScript source code
        v8::Local<v8::String> source = v8::String::NewFromUtf8Literal(isolate,
            "'Hello, World from V8!'"
        );

        // Compile the source code
        v8::Local<v8::Script> script = v8::Script::Compile(context, source).ToLocalChecked();

        // Run the script to get the result
        v8::Local<v8::Value> result = script->Run(context).ToLocalChecked();

        // Convert the result to a UTF8 string and print it
        v8::String::Utf8Value utf8(isolate, result);
        std::cout << "Result: " << *utf8 << "\n\n";
    }

    void runVariableExample(v8::Local<v8::Context> context) {
        std::cout << "2. Variables and Math:\n";

        const char* js_code = R"(
            var x = 10;
            var y = 20;
            var message = 'The sum of ' + x + ' and ' + y + ' is: ' + (x + y);
            message;
        )";

        v8::Local<v8::String> source = v8::String::NewFromUtf8(isolate, js_code).ToLocalChecked();
        v8::Local<v8::Script> script = v8::Script::Compile(context, source).ToLocalChecked();
        v8::Local<v8::Value> result = script->Run(context).ToLocalChecked();

        v8::String::Utf8Value utf8(isolate, result);
        std::cout << *utf8 << "\n\n";
    }

    void runObjectExample(v8::Local<v8::Context> context) {
        std::cout << "3. Objects and Arrays:\n";

        const char* js_code = R"(
            var person = {
                name: 'John Doe',
                age: 30,
                greet: function() {
                    return 'Hello, my name is ' + this.name + ' and I am ' + this.age + ' years old.';
                }
            };
            
            var numbers = [1, 2, 3, 4, 5];
            var sum = numbers.reduce(function(acc, num) { return acc + num; }, 0);
            
            person.greet() + ' Sum of numbers: ' + sum;
        )";

        v8::Local<v8::String> source = v8::String::NewFromUtf8(isolate, js_code).ToLocalChecked();
        v8::Local<v8::Script> script = v8::Script::Compile(context, source).ToLocalChecked();
        v8::Local<v8::Value> result = script->Run(context).ToLocalChecked();

        v8::String::Utf8Value utf8(isolate, result);
        std::cout << *utf8 << "\n\n";
    }

    void runErrorExample(v8::Local<v8::Context> context) {
        std::cout << "4. Error Handling:\n";

        const char* js_code = "throw new Error('This is a test error');";

        v8::Local<v8::String> source = v8::String::NewFromUtf8(isolate, js_code).ToLocalChecked();
        v8::Local<v8::Script> script = v8::Script::Compile(context, source).ToLocalChecked();

        v8::TryCatch try_catch(isolate);
        v8::Local<v8::Value> result = script->Run(context).ToLocalChecked();

        if (try_catch.HasCaught()) {
            v8::Local<v8::Value> exception = try_catch.Exception();
            v8::String::Utf8Value exception_str(isolate, exception);
            std::cout << "Caught JavaScript exception: " << *exception_str << "\n\n";
        }
        else {
            v8::String::Utf8Value utf8(isolate, result);
            std::cout << "Result: " << *utf8 << "\n\n";
        }
    }

    void runCppFunctionExample(v8::Local<v8::Context> context) {
        std::cout << "5. C++ Function Integration:\n";

        // Create a template for the global object
        v8::Local<v8::ObjectTemplate> global = v8::ObjectTemplate::New(isolate);

        // Bind the print function
        global->Set(v8::String::NewFromUtf8Literal(isolate, "print"),
            v8::FunctionTemplate::New(isolate, Print));

        // Bind the add function
        global->Set(v8::String::NewFromUtf8Literal(isolate, "add"),
            v8::FunctionTemplate::New(isolate, Add));

        // Create a new context with the global template
        v8::Local<v8::Context> new_context = v8::Context::New(isolate, nullptr, global);
        v8::Context::Scope context_scope(new_context);

        const char* js_code = R"(
            print('Hello from C++ function!');
            var result = add(15, 25);
            print('15 + 25 = ' + result);
            result;
        )";

        v8::Local<v8::String> source = v8::String::NewFromUtf8(isolate, js_code).ToLocalChecked();
        v8::Local<v8::Script> script = v8::Script::Compile(new_context, source).ToLocalChecked();
        v8::Local<v8::Value> result = script->Run(new_context).ToLocalChecked();

        v8::String::Utf8Value utf8(isolate, result);
        std::cout << "Final result: " << *utf8 << "\n\n";
    }

    // C++ function to be called from JavaScript
    static void Print(const v8::FunctionCallbackInfo<v8::Value>& args) {
        bool first = true;
        for (int i = 0; i < args.Length(); i++) {
            v8::HandleScope handle_scope(args.GetIsolate());
            if (first) {
                first = false;
            }
            else {
                std::cout << " ";
            }
            v8::String::Utf8Value str(args.GetIsolate(), args[i]);
            std::cout << *str;
        }
        std::cout << std::endl;
    }

    // C++ function to add two numbers
    static void Add(const v8::FunctionCallbackInfo<v8::Value>& args) {
        if (args.Length() < 2) {
            args.GetIsolate()->ThrowException(
                v8::String::NewFromUtf8Literal(args.GetIsolate(), "Wrong number of arguments"));
            return;
        }

        if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
            args.GetIsolate()->ThrowException(
                v8::String::NewFromUtf8Literal(args.GetIsolate(), "Arguments must be numbers"));
            return;
        }

        double value_a = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
        double value_b = args[1]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
        double result = value_a + value_b;

        args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), result));
    }
};

// Helper function to set global variables from C++
void SetGlobalVariable(v8::Local<v8::Context> context, const std::string& name, const std::string& value) {
    v8::Isolate* isolate = context->GetIsolate();
    v8::Local<v8::String> key = v8::String::NewFromUtf8(isolate, name.c_str()).ToLocalChecked();
    v8::Local<v8::String> val = v8::String::NewFromUtf8(isolate, value.c_str()).ToLocalChecked();
    context->Global()->Set(context, key, val).FromJust();
}

// Helper function to get global variables from JavaScript
std::string GetGlobalVariable(v8::Local<v8::Context> context, const std::string& name) {
    v8::Isolate* isolate = context->GetIsolate();
    v8::Local<v8::String> key = v8::String::NewFromUtf8(isolate, name.c_str()).ToLocalChecked();
    v8::Local<v8::Value> value = context->Global()->Get(context, key).ToLocalChecked();
    v8::String::Utf8Value utf8_value(isolate, value);
    return std::string(*utf8_value);
}

int main() {
    try {
        V8HelloWorld v8_app;
        v8_app.runHelloWorld();

        std::cout << "V8 Hello World completed successfully!\n";

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
