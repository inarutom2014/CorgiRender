#include "WindowsWindow.h"
#include <Windows.h>

namespace Corgi
{
    namespace Core
    {
        static HWND CreateWindowInternal(const TCHAR *title, int width, int height)
        {
            CORGI_CHECK(width > 0 && height > 0);
            DWORD style = WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
            RECT rect;
            HWND handle;
            // TCHAR title[CORGI_LINE_SIZE];
            rect.left = 0;
            rect.top = 0;
            rect.right = width;
            rect.bottom = height;
            AdjustWindowRect(&rect, style, 0);
            width = rect.right - rect.left;
            height = rect.bottom - rect.top;

            handle = CreateWindow(PlatformMisc::WINDOW_CLSS_NAME, title, style,
                                    CW_USEDEFAULT, CW_USEDEFAULT, width, height,
                                    nullptr, nullptr, GetModuleHandle(nullptr), nullptr);
            return handle;
        }

        static void CreateSurfaceInternal(HWND handle, int width, int height, HDC *outMemoryDC)
        {
            BITMAPINFOHEADER biHeader;
            
        }

        WindowsWindow::WindowsWindow(const TCHAR *title, int width, int height)
        {
            HWND handle;
            // image_t *surface;
            HDC memoryDC;
            handle = CreateWindowInternal(title, width, height);

        }
    }
}