set(V8_DIR ${COCOS2DX_ROOT_PATH}/external/V8)

set(JSB_SRC
    ScriptEngine.cpp
    JsbUtils.cpp
    # Core/jsb_module_register.cpp
)

set(JSB_HEADERS
    JsbBase.h
    JsbConfig.h
    HelperMacros.h
    ScriptEngine.hpp
    # Core/jsb_module_register.hpp
)

add_library(jsb STATIC ${JSB_SRC} ${JSB_HEADERS})

# target_link_libraries(jsb cocos2d)
# add_dependencies(jsb cocos2d)

# PUBLIC: consumers of jsb (cocos2d, app) get V8 and jsb headers automatically
target_include_directories(jsb
    PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC  ${V8_DIR}/Inc
)


if(WINDOWS)
    target_link_directories(jsb PUBLIC ${V8_DIR}/Lib/Win32)
    target_link_libraries(jsb PUBLIC v8_monolith.lib winmm.lib dbghelp.lib shlwapi.lib)
    # target_compile_definitions(jsb PRIVATE _USRJSSTATIC)
endif()

set_target_properties(jsb PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "Internal"
)

# if(WINDOWS)
#     # precompiled header
#     target_sources(jsb PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/precheader.cpp")
#     set_target_properties(jsb PROPERTIES COMPILE_FLAGS "/Yuprecheader.h /FIprecheader.h")
#     set_source_files_properties("${CMAKE_CURRENT_SOURCE_DIR}/precheader.cpp" PROPERTIES COMPILE_FLAGS "/Ycprecheader.h")
# endif()
