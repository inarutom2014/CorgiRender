#include "WindowsPlatformMisc.h"
#include "../CoreTypes.h"
#include "../Windows/WindowsWindow.h"
#include <windows.h>

namespace Corgi
{
    namespace Core
    {
		static const ANSICHAR *WINDOW_TITLE = "Viewer";
		static const int32 WINDOW_WIDTH = 800;
		static const int32 WINDOW_HEIGHT = 600;

        static LRESULT CALLBACK process_message(HWND hWnd, UINT uMsg,
                                        WPARAM wParam, LPARAM lParam)
        {
			WindowsWindow *window = (WindowsWindow*)GetProp(hWnd, TEXT("Entry"));
			if (uMsg == WM_CLOSE) {
				window->SetShouldClose(true);
			}
			else
			{
				return DefWindowProc(hWnd, uMsg, wParam, lParam);
			}
        }

        void WindowsPlatformMisc::PlatformInit()
        {
            ATOM class_atom;
            WNDCLASS window_class;
            window_class.style = CS_HREDRAW | CS_VREDRAW;
            window_class.lpfnWndProc = process_message;
			window_class.cbClsExtra = 0;
			window_class.cbWndExtra = 0;
            window_class.hInstance = GetModuleHandle(nullptr);
            window_class.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
            window_class.hCursor = LoadCursor(nullptr, IDC_ARROW);
            window_class.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
            window_class.lpszMenuName = nullptr;
            window_class.lpszClassName = TEXT("Class");
            class_atom = RegisterClass(&window_class);
			assert(class_atom != 0);
            CORGI_UNUSED_VARIABLE(class_atom);
        }

		void WindowsPlatformMisc::MainLoop()
		{
			auto window = CreatePlatformWindow(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
			while (!window->ShouldClose())
			{
				PollEvents();
			}
			delete window;
		}

		void WindowsPlatformMisc::PollEvents()
		{
			MSG message;
			while (PeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
		}

        void WindowsPlatformMisc::PlatformTerminate()
        {
            UnregisterClass(TEXT("Class"), GetModuleHandle(nullptr));
        }

		GenericWindow *WindowsPlatformMisc::CreatePlatformWindow(const ANSICHAR* title, int32 width, int32 height)
		{
			WindowsWindow *window = new WindowsWindow(title, width, height);
			return window;
		}
    }
}