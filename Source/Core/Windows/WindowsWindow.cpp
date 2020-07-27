#include "WindowsWindow.h"
#include "../Graphic/Image.h"
#include <Windows.h>
using Image = Corgi::Core::Image;

namespace Corgi
{
    namespace Core
    {
        static const WIDECHAR * const WINDOW_ENTRY_NAME = L"Entry";

        static HWND CreateWindowInternal(const ANSICHAR* title, int32 width, int32 height)
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

            HWND handle = CreateWindow(TEXT("Class"), title, style,
                CW_USEDEFAULT, CW_USEDEFAULT, width, height,
                nullptr, nullptr, GetModuleHandle(nullptr), nullptr);
            return handle;
        }

        static Image* CreateSurfaceInternal(HWND handle, int32 width, int32 height, HDC* outMemoryDC)
        {
            HDC windowDC = GetDC(handle);
            HDC memoryDC = CreateCompatibleDC(windowDC);
            ReleaseDC(handle, windowDC);

            Image* surface = Corgi::Core::Image::Create(width, height, 4, Image::EImageFormat::LDR);

            BITMAPINFOHEADER biHeader;
            memset(&biHeader, 0, sizeof(BITMAPCOREHEADER));
            biHeader.biSize = sizeof(BITMAPCOREHEADER);
            biHeader.biWidth = width;
            //窗口坐标系的Y坐标朝下，bitmap的Y坐标朝上，所以要加个负号
            biHeader.biHeight = -height;
            biHeader.biPlanes = 1;
            biHeader.biBitCount = 32;
            biHeader.biCompression = BI_RGB;
            HBITMAP hbitmap = CreateDIBSection(memoryDC, (BITMAPINFO*)&biHeader, DIB_RGB_COLORS, (void**)surface->GetLdrBuffer(), nullptr, 0);
            CORGI_CHECK(hbitmap != nullptr);
            HBITMAP oldBitmap = (HBITMAP)SelectObject(memoryDC, hbitmap);
            DeleteObject(oldBitmap);
            *outMemoryDC = memoryDC;
            return surface;
        }

        WindowsWindow::WindowsWindow(const ANSICHAR *title, int32 width, int32 height)
            : m_handle(0), m_memoryDC(nullptr), m_surface(nullptr)
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

        void WindowsWindow::DrawBuffer()
        {
            
        }
    }
}