#pragma once

#include "../GenericPlatform/GenericPlatformMisc.h"

namespace Corgi
{
    namespace Core
    {
        class WindowsPlatformMisc : public GenericPlatformMisc
        {
            public:
                static void PlatformInit();
                static void PlatformTerminate();
                static GenericWindow* CreateWindow(const TCHAR* title, int width, int height) {
                    return nullptr;
                }

                static const WIDECHAR *const WINDOW_CLSS_NAME;
        };
        typedef WindowsPlatformMisc PlatformMisc;
    }
}