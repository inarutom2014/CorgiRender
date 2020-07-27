#include "WindowsPlatformMisc.h"
#include "../CoreTypes.h"
#include "../Windows/WindowsWindow.h"
#include <windows.h>

namespace Corgi
{
    namespace Core
    {
        static LRESULT CALLBACK process_message(HWND hWnd, UINT uMsg,
                                        WPARAM wParam, LPARAM lParam)
        {
            //TODO
            return 0;
        }

        void WindowsPlatformMisc::PlatformInit()
        {
            ATOM class_atom;
            WNDCLASS window_class;
            window_class.style = CS_HREDRAW | CS_VREDRAW;
            window_class.lpfnWndProc = process_message;
            window_class.cbClsExtra = 0;
            window_class.hInstance = GetModuleHandle(nullptr);
            window_class.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
            window_class.hCursor = LoadCursor(nullptr, IDC_ARROW);
            window_class.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
            window_class.lpszMenuName = nullptr;
            window_class.lpszClassName = TEXT("Class");
            class_atom = RegisterClass(&window_class);
            CORGI_UNUSED_VARIABLE(class_atom);
        }

        void WindowsPlatformMisc::PlatformTerminate()
        {
            UnregisterClass(TEXT("Class"), GetModuleHandle(nullptr));
        }


        /*static GenericWindow* WindowsPlatformMisc::CreateWindow(const TCHAR* title, int width, int height)
        {
            GenericWindow* unusedWindow;
            return unusedWindow;
        }*/
    }
}