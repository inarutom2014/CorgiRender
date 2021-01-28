#pragma once

#include "../GenericPlatform/GenericPlatformMisc.h"

namespace Corgi
{
    namespace Core
    {
		class GenericWindow;
        class WindowsPlatformMisc : public GenericPlatformMisc
        {
            public:
                static void PlatformInit();
				static void MainLoop();
				static void PollEvents();
                static void PlatformTerminate();
				static GenericWindow *CreatePlatformWindow(const ANSICHAR* title, int32 width, int32 height);
        };
        typedef WindowsPlatformMisc PlatformMisc;
    }
}