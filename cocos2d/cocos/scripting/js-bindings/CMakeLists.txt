set(V8_DIR ${COCOS2DX_ROOT_PATH}/external/V8)

set(JSB_SRC
    ScriptEngine.cpp
    JsbUtils.cpp
    JsbCtor.cpp
    Core/jsb_module_register.cpp
    Core/jsb_global.cpp
    Core/JsbClass.cpp
    Core/JsbObject.cpp
    Core/JsbObjectWrap.cpp
    Core/RefCounter.cpp

    Utils/MappingUtils.cpp

    Wrapper/JsbCommon.cpp
    Wrapper/JsbAllCocos.cpp
    Wrapper/JsbNode.cpp
    Wrapper/JsbScene.cpp
    Wrapper/JsbDirector.cpp
    Wrapper/JsbLabel.cpp
)

set(JSB_HEADERS
    JsbBase.h
    JsbConfig.h
    JsbCtor.hpp
    HelperMacros.h
    ScriptEngine.hpp
    Core/jsb_module_register.hpp
    Core/jsb_global.hpp
    Core/jsb_conversions.hpp
    Core/JsbClass.hpp
    Core/JsbObject.hpp
    Core/JsbObjectWrap.hpp
    Core/RefCounter.hpp

    Utils/MappingUtils.hpp

    Wrapper/JsbAllCocos.hpp
    Wrapper/JsbCommon.hpp
    Wrapper/JsbNode.hpp
    Wrapper/JsbScene.hpp
    Wrapper/JsbDirector.hpp
    Wrapper/JsbLabel.hpp
)

add_library(jsb STATIC ${JSB_SRC} ${JSB_HEADERS})

if(WINDOWS)
    target_link_directories(jsb PUBLIC ${V8_DIR}/Lib/Win32)
    target_link_libraries(jsb PUBLIC cocos2d v8_monolith.deb.lib winmm.lib dbghelp.lib shlwapi.lib)
    # target_compile_definitions(jsb PRIVATE _USRJSSTATIC)
endif()

# target_link_libraries(jsb PUBLIC cocos2d)
add_dependencies(jsb cocos2d)

# PUBLIC: consumers of jsb (cocos2d, app) get V8 and jsb headers automatically
target_include_directories(jsb
    PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC  ${V8_DIR}/Inc
)



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
