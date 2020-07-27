cmake_minimum_required(VERSION 3.10)
project(CorgiRenderer LANGUAGES CXX)

#Specify the C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Header and Source
set(HEADERS
    Source/Core/GenericPlatform/GenericPlatform.h
    Source/Core/GenericPlatform/GenericWindow.h
    Source/Core/Graphic/Image.h
    Source/Core/HAL/Platform.h
    Source/Core/Misc/AssertionMacros.h
    Source/Core/Misc/CoreMacrosDefines.h
    Source/Core/CoreTypes.h
)

set(SOURCES
    Source/Core/GenericPlatform/GenericWindow.cpp
    Source/Core/Graphic/Image.cpp
    Source/main.cpp
)

if(MSVC)
    set(HEADERS
        ${HEADERS}
        Source/Core/Windows/WindowsPlatform.h
        Source/Core/Windows/WindowsPlatformMisc.h
        Source/Core/Windows/WindowsWindow.h
    )
    set(SOURCES 
        ${SOURCES}
        Source/Core/Windows/WindowsPlatformMisc.cpp
        Source/Core/Windows/WindowsWindow.cpp
    )
endif()

# Target

set(TARGET Viewer)

add_executable(${TARGET} ${HEADERS} ${SOURCES})

# if(MSVC)
#     target_compile_options(${TARGET} PRIVATE /W4 /D_CRT_SECURE_NO_WARNINGS)
#     target_compile_options(${TARGET} PRIVATE /fp:fast)
# else()
#     target_compile_options(${TARGET} PRIVATE -Wall -Wextra -pedantic)
#     target_compile_options(${TARGET} PRIVATE -ffast-math)
# endif()


set_directory_properties(PROPERTIES VS_STARTUP_PROJECT ${TARGET})

