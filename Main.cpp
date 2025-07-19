#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "quickjs-msvc.h"

class QuickJSWrapper {
private:
    JSRuntime* rt;
    JSContext* ctx;

public:
    QuickJSWrapper() : rt(nullptr), ctx(nullptr) {
        // Initialize QuickJS runtime and context
        rt = JS_NewRuntime();
        if (!rt) {
            throw std::runtime_error("Failed to create QuickJS runtime");
        }

        ctx = JS_NewContext(rt);
        if (!ctx) {
            JS_FreeRuntime(rt);
            throw std::runtime_error("Failed to create QuickJS context");
        }
    }

    ~QuickJSWrapper() {
        if (ctx) {
            JS_FreeContext(ctx);
        }
        if (rt) {
            JS_FreeRuntime(rt);
        }
    }

    // Execute JavaScript code and return result as string
    std::string eval(const std::string& code) {
        JSValue result = JS_Eval(ctx, code.c_str(), code.length(), "<eval>", JS_EVAL_TYPE_GLOBAL);

        if (JS_IsException(result)) {
            JSValue exception = JS_GetException(ctx);
            const char* str = JS_ToCString(ctx, exception);
            std::string error = str ? str : "Unknown error";
            JS_FreeCString(ctx, str);
            JS_FreeValue(ctx, exception);
            JS_FreeValue(ctx, result);
            throw std::runtime_error("JavaScript error: " + error);
        }

        const char* str = JS_ToCString(ctx, result);
        std::string resultStr = str ? str : "";
        JS_FreeCString(ctx, str);
        JS_FreeValue(ctx, result);

        return resultStr;
    }

    // Set a global variable
    void setGlobal(const std::string& name, const std::string& value) {
        JSValue jsValue = JS_NewString(ctx, value.c_str());
        JS_SetPropertyStr(ctx, JS_GetGlobalObject(ctx), name.c_str(), jsValue);
    }

    void setGlobal(const std::string& name, double value) {
        JSValue jsValue = JS_NewFloat64_(ctx, value);
        JS_SetPropertyStr(ctx, JS_GetGlobalObject(ctx), name.c_str(), jsValue);
    }

    // Get a global variable as string
    std::string getGlobalString(const std::string& name) {
        JSValue global = JS_GetGlobalObject(ctx);
        JSValue prop = JS_GetPropertyStr(ctx, global, name.c_str());

        const char* str = JS_ToCString(ctx, prop);
        std::string result = str ? str : "";
        JS_FreeCString(ctx, str);
        JS_FreeValue(ctx, prop);
        JS_FreeValue(ctx, global);

        return result;
    }

    // Register a C++ function to be callable from JavaScript
    void registerFunction(const std::string& name, JSCFunction* func) {
        JSValue global = JS_GetGlobalObject(ctx);
        JSValue jsFunc = JS_NewCFunction(ctx, func, name.c_str(), 0);
        JS_SetPropertyStr(ctx, global, name.c_str(), jsFunc);
        JS_FreeValue(ctx, global);
    }

    JSContext* getContext() { return ctx; }
};

// Example C++ function to be called from JavaScript
static JSValue js_hello(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
    if (argc > 0) {
        const char* name = JS_ToCString(ctx, argv[0]);
        std::string message = "Hello, " + std::string(name) + " from C++!";
        JS_FreeCString(ctx, name);
        return JS_NewString(ctx, message.c_str());
    }
    return JS_NewString(ctx, "Hello from C++!");
}

// Example function that takes multiple parameters
static JSValue js_add_numbers(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
    if (argc < 2) {
        return JS_ThrowTypeError(ctx, "Expected 2 arguments");
    }

    double a, b;
    if (JS_ToFloat64(ctx, &a, argv[0]) < 0 || JS_ToFloat64(ctx, &b, argv[1]) < 0) {
        return JS_ThrowTypeError(ctx, "Arguments must be numbers");
    }

    return JS_NewFloat64_(ctx, a + b);
}

// Example function that returns an object
static JSValue js_create_object(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
    JSValue obj = JS_NewObject(ctx);

    JS_SetPropertyStr(ctx, obj, "name", JS_NewString(ctx, "Sample Object"));
    JS_SetPropertyStr(ctx, obj, "value", JS_NewInt32_(ctx, 42));
    JS_SetPropertyStr(ctx, obj, "timestamp", JS_NewFloat64_(ctx, 1234567890.123));

    return obj;
}

int main() {
    try {
        QuickJSWrapper js;

        std::cout << "=== QuickJS C++ Integration Example ===\n\n";

        // 1. Basic JavaScript execution
        std::cout << "1. Basic Math:\n";
        std::cout << "2 + 3 = " << js.eval("2 + 3") << "\n";
        std::cout << "Math.PI = " << js.eval("Math.PI") << "\n\n";

        // 2. String operations
        std::cout << "2. String Operations:\n";
        std::cout << js.eval("'Hello ' + 'World!'") << "\n";
        std::cout << js.eval("'JavaScript'.toUpperCase()") << "\n\n";

        // 3. Working with variables
        std::cout << "3. Variables:\n";
        js.setGlobal("myName", "QuickJS User");
        js.setGlobal("myAge", 25.5);
        std::cout << "Name: " << js.getGlobalString("myName") << "\n";
        std::cout << "Age: " << js.eval("myAge") << "\n\n";

        // 4. Complex JavaScript code
        std::cout << "4. Complex Code (Fibonacci):\n";
        std::string fibCode = R"(
            function fibonacci(n) {
                if (n <= 1) return n;
                return fibonacci(n - 1) + fibonacci(n - 2);
            }
            fibonacci(10);
        )";
        std::cout << "fibonacci(10) = " << js.eval(fibCode) << "\n\n";

        // 5. Register C++ functions
        std::cout << "5. C++ Functions in JavaScript:\n";
        js.registerFunction("hello", js_hello);
        js.registerFunction("addNumbers", js_add_numbers);
        js.registerFunction("createObject", js_create_object);

        std::cout << js.eval("hello()") << "\n";
        std::cout << js.eval("hello('Alice')") << "\n";
        std::cout << "5 + 7 = " << js.eval("addNumbers(5, 7)") << "\n\n";

        // 6. Working with objects
        std::cout << "6. Object Handling:\n";
        std::string objCode = R"(
            var obj = createObject();
            'Name: ' + obj.name + ', Value: ' + obj.value;
        )";
        std::cout << js.eval(objCode) << "\n\n";

        // 7. Arrays and loops
        std::cout << "7. Arrays and Loops:\n";
        std::string arrayCode = R"(
            var arr = [1, 2, 3, 4, 5];
            var sum = 0;
            for (var i = 0; i < arr.length; i++) {
                sum += arr[i];
            }
            'Array: [' + arr.join(', ') + '], Sum: ' + sum;
        )";
        std::cout << js.eval(arrayCode) << "\n\n";

        // 8. JSON handling
        std::cout << "8. JSON Handling:\n";
        std::string jsonCode = R"(
            var data = { users: [
                { name: 'John', age: 30 },
                { name: 'Jane', age: 25 }
            ]};
            JSON.stringify(data, null, 2);
        )";
        std::cout << "JSON Data:\n" << js.eval(jsonCode) << "\n\n";

        // 9. Error handling example
        std::cout << "9. Error Handling:\n";
        try {
            js.eval("nonExistentFunction()");
        }
        catch (const std::exception& e) {
            std::cout << "Caught error: " << e.what() << "\n\n";
        }

        // 10. Performance test
        std::cout << "10. Performance Test:\n";
        std::string perfCode = R"(
    async function fetchData() {
        // QuickJS supports modern async syntax
        return await new Promise(resolve => resolve("data"));
    }
            var start = Date.now();
            var result = 0;
            for (var i = 0; i < 1000000; i++) {
                result += i;
            }
            var end = Date.now();
            'Calculated sum of 1M numbers in ' + (end - start) + 'ms, Result: ' + result;
        )";
        std::cout << js.eval(perfCode) << "\n";

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}