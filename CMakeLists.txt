SET(PROJECT_NAME "cocosTS-Wrapper")
SET(PROJECT_VERSION "0.1.0")
cmake_minimum_required(VERSION 3.10)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE "Release")

add_executable(${PROJECT_NAME} Main.cpp)

add_definitions(-DPLATFORM_WINDOWS)
add_definitions(-DFORCE_USE_STATIC_V8_LIB)

# link static library
target_link_directories(${PROJECT_NAME} PUBLIC "QuickJS/Lib/Win64")
# target_link_directories(${PROJECT_NAME} PUBLIC "V8/Lib/Win64DLL")
target_link_libraries(${PROJECT_NAME} PRIVATE quickjs.dll)
target_include_directories(${PROJECT_NAME} PUBLIC "QuickJS/Inc")

if(MSVC)
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
endif()