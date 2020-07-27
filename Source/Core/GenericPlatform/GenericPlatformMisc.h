#pragma once

#include "../CoreTypes.h"
#include "GenericWindow.h"

namespace Corgi
{
    namespace Core
    {
        class GenericWindow;

        class GenericPlatformMisc
        {
        public:
            static void PlatformInit() {}

            static void PlatformTerminate() {}

            /*static GenericWindow *CreateWindow_(const TCHAR *title, int32 width, int32 height)
            {
                return nullptr;
            }*/
        };
    } // namespace Core
} // namespace Corgi