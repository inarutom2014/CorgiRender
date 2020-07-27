#pragma once

#ifdef _WIN32 || _WIN64
#include "../Windows/WindowsPlatform.h"
#include "../Windows/WindowsPlatformMisc.h"
#endif

using PlatformTypes = Corgi::Core::PlatformTypes;

typedef PlatformTypes::uint16 uint16;
typedef PlatformTypes::WIDECHAR WIDECHAR;
typedef PlatformTypes::ANSICHAR ANSICHAR;
typedef PlatformTypes::TCHAR TCHAR;