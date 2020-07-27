#pragma once

#if defined(_WIN32) || defined(_WIN64)
#include "../Windows/WindowsPlatform.h"
#include "../Windows/WindowsPlatformMisc.h"
#endif

namespace Corgi
{
	using PlatformTypes = Corgi::Core::PlatformTypes;

	typedef PlatformTypes::uint8 uint8;
	typedef PlatformTypes::uint16 uint16;
	typedef PlatformTypes::uint32 uint32;
	typedef PlatformTypes::uint64 uint64;

	typedef PlatformTypes::int8 int8;
	typedef PlatformTypes::int16 int16;
	typedef PlatformTypes::int32 int32;
	typedef PlatformTypes::int64 int64;

	typedef PlatformTypes::WIDECHAR WIDECHAR;
	typedef PlatformTypes::ANSICHAR ANSICHAR;
	typedef PlatformTypes::TCHAR TCHAR;
}