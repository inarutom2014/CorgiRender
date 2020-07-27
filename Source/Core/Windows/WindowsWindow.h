#pragma once

#include "../GenericPlatform/GenericWindow.h"
#include "../CoreTypes.h"

namespace Corgi
{
    namespace Core
    {
        class WindowsWindow : public GenericWindow
        {
        public:
            WindowsWindow(const TCHAR *title, int width, int height);
        };
    } // namespace Core
} // namespace Corgi