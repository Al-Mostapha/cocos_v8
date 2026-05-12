set(V8_DIR ${COCOS2DX_ROOT_PATH}/external/V8)

set(JSB_SRC
    ScriptEngine.cpp
)

set(JSB_HEADERS
    JsbBase.h
    JsbConfig.h
    HelperMacros.h
    ScriptEngine.hpp
)

add_library(jsb STATIC ${JSB_SRC} ${JSB_HEADERS})

# PUBLIC: consumers of jsb (cocos2d, app) get V8 and jsb headers automatically
target_include_directories(jsb
    PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC  ${V8_DIR}/Inc
)

if(WINDOWS)
    target_link_directories(jsb PUBLIC ${V8_DIR}/Lib/Win32)
    target_link_libraries(jsb PUBLIC v8_monolith.lib winmm.lib dbghelp.lib shlwapi.lib)
endif()

set_target_properties(jsb PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "Internal"
)
