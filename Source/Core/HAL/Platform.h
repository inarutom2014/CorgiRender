#pragma once

#ifdef _WIN32 || _WIN64
    #include "Core/Windows/WindowsPlatform.h"
#endif

using PlatformTypes = Corgi::Core::PlatformTypes;

typedef PlatformTypes::uint8 uint8;

