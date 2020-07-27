#pragma once

#include "../GenericPlatform/GenericWindow.h"
#include "../CoreTypes.h"
#include <Windows.h>

namespace Corgi
{
    namespace Core
    {
        class Image;

        class WindowsWindow : public GenericWindow
        {
        public:
            WindowsWindow(const ANSICHAR *title, int width, int height);
            ~WindowsWindow();
            virtual void DrawBuffer() override;
        private:
            HWND m_handle;
            HDC m_memoryDC;
            Image *m_surface;
        };
    } // namespace Core
} // namespace Corgi