#
#	Copyright (c) 2024 Sidhin S Thomas. All rights reserved
#

cmake_minimum_required(VERSION 3.20)
project(SFMLUILib 
    VERSION 0.0.0
    LANGUAGES CXX
    DESCRIPTION "User Ineterface Library built on SFML")

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 11b73743c42cf7ecd7c596ba83fdbf1150ffa96c
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(SFML)

add_executable(SFMLUILib
    "src/Main.cpp"
    "src/MenuImpl.h"
    "src/MenuImpl.cpp"
    "src/ButtonImpl.cpp"
    "src/ButtonImpl.h"
    "src/CommonText.cpp"
    "src/IControl.cpp"
    "src/Menu.h"
    "src/MenuImpl.cpp"
    "src/MenuImpl.h"
    "src/ScreenImpl.cpp"
    "src/ScreenImpl.h"
    "src/SubscriptionManager.cpp"
    "src/SubscriptionManager.h"
    "src/IControl.h"
    "src/IPresentation.h"
    "src/IScreen.h"
    "src/CommonText.h"
    "src/IButton.h"
    "src/CommonStructures.h"
)

target_link_libraries(SFMLUILib PUBLIC sfml-graphics)
target_include_directories(
    SFMLUILib
    PUBLIC
    "public"
    "include"
)

if(WIN32)
    add_custom_command(
        TARGET SFMLUILib
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:SFMLUILib>
        VERBATIM)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)