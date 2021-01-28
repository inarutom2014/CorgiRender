#pragma once

#include "../CoreTypes.h"

namespace Corgi
{
    namespace Core
    {
        class GenericWindow;

        class GenericPlatformMisc
        {
        public:
            static void PlatformInit() {}
			static void MainLoop() {}
            static void PlatformTerminate() {}

            static GenericWindow *CreatePlatformWindow(const ANSICHAR *title, int32 width, int32 height)
            {
                return nullptr;
            }
        };
    } // namespace Core
} // namespace Corgi