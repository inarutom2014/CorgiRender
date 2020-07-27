#pragma once

#include "../GenericPlatform/GenericPlatform.h"

namespace Corgi
{
    namespace Core
    {
        struct WindowsPlatformTypes : public GenericPlatformTypes
        {
        };

        typedef WindowsPlatformTypes PlatformTypes;
    } // namespace Core

} // namespace Corgi

#define PLATFORM_LITTLE_ENDIAN      1
