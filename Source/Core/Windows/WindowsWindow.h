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
            WindowsWindow(const ANSICHAR *title, int32 width, int32 height);
            ~WindowsWindow();
			virtual bool ShouldClose() const override;
            virtual void DrawBuffer() override;

			inline void SetShouldClose(bool inClose) { m_bClose = inClose; }
        private:
            HWND m_handle;
            HDC m_memoryDC;
            Image *m_surface;
			bool m_bClose;
        };
    } // namespace Core
} // namespace Corgi