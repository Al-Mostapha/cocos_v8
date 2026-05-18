#pragma once

#include "libplatform/libplatform.h"

// #define V8_DEPRECATION_WARNINGS 1
// #define V8_IMMINENT_DEPRECATION_WARNINGS 1
// #define V8_HAS_ATTRIBUTE_DEPRECATED_MESSAGE 1

#include "v8.h"

#include <string>
#include <string.h> // Resolves that memset, memcpy aren't found while APP_PLATFORM >= 22 on Android
#include <vector>
#include <unordered_map>
#include <functional>
#include <algorithm> // for std::find
#include <chrono>
#include <assert.h>

#include "HelperMacros.h"

using V8FinalizeFunc = void (*)(void *nativeObj);
