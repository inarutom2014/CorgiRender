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

            static GenericWindow *CreateWindow(const TCHAR *title, int width, int height)
            {
                return nullptr;
            }
        };
    } // namespace Core
} // namespace Corgi