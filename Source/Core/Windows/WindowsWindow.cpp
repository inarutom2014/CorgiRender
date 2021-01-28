#include "WindowsWindow.h"
#include "../Graphic/Image.h"
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <Windows.h>

#ifdef _MSC_VER
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")
#endif

using Image = Corgi::Core::Image;

namespace Corgi
{
    namespace Core
    {
        static HWND CreateWindowInternal(const ANSICHAR* title_, int32 width, int32 height)
        {
            CORGI_CHECK(width > 0 && height > 0);
            DWORD style = WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
            RECT rect;
            rect.left = 0;
            rect.top = 0;
            rect.right = width;
            rect.bottom = height;
            AdjustWindowRect(&rect, style, 0);
            width = rect.right - rect.left;
            height = rect.bottom - rect.top;

#ifdef UNICODE
			wchar_t title[LINE_SIZE];
			mbstowcs(title, title_, LINE_SIZE);
#else
			const char *title = title_;
#endif

            HWND handle = CreateWindow(TEXT("Class"), title, style,
                CW_USEDEFAULT, CW_USEDEFAULT, width, height,
				NULL, NULL, GetModuleHandle(NULL), NULL);
			assert(handle != NULL);
            return handle;
        }

        static Image* CreateSurfaceInternal(HWND handle, int32 width, int32 height, HDC* outMemoryDC)
        {
            HDC windowDC = GetDC(handle);
            HDC memoryDC = CreateCompatibleDC(windowDC);
            ReleaseDC(handle, windowDC);

            Image* surface = Corgi::Core::Image::Create(width, height, 4, Image::EImageFormat::LDR);
			surface->ClearLdrBuffer();

			LPVOID ptr = surface->GetLdrBuffer();

			BITMAPINFO bi = { { sizeof(BITMAPINFOHEADER), width, -height, 1, 32, BI_RGB,
				width * height * 4, 0, 0, 0, 0 } };

			uint8 *ldrBuffer = surface->GetLdrBuffer();
            HBITMAP hbitmap = CreateDIBSection(memoryDC, &bi, DIB_RGB_COLORS, &ptr, 0, 0);
            CORGI_CHECK(hbitmap != nullptr);
            HBITMAP oldBitmap = (HBITMAP)SelectObject(memoryDC, hbitmap);
            DeleteObject(oldBitmap);
            *outMemoryDC = memoryDC;
            return surface;
        }

        WindowsWindow::WindowsWindow(const ANSICHAR *title, int32 width, int32 height)
            : m_handle(0), m_memoryDC(nullptr), m_surface(nullptr), m_bClose(false)
        {
            HWND handle;
            // image_t *surface;
            HDC memoryDC;
            handle = CreateWindowInternal(title, width, height);
            Image* surface = CreateSurfaceInternal(handle, width, height, &memoryDC);
            m_handle = handle;
            m_memoryDC = memoryDC;
            m_surface = surface;
            SetProp(handle, TEXT("Entry"), this);
            ShowWindow(handle, SW_SHOW);
        }

        WindowsWindow::~WindowsWindow()
        {
            ShowWindow(m_handle, SW_HIDE);
            RemoveProp(m_handle, TEXT("Entry"));

            DeleteDC(m_memoryDC);
            DestroyWindow(m_handle);

            delete m_surface;
        }

		bool WindowsWindow::ShouldClose() const
		{
			return m_bClose;
		}

        void WindowsWindow::DrawBuffer()
        {
            
        }
    }
}