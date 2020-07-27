#include "GenericWindow.h"

namespace Corgi
{
    namespace Core
    {
        GenericWindow::GenericWindow()
        {

        }

        GenericWindow::~GenericWindow()
        {

        }

        GenericWindow* Create(int width, int height)
        {
            return new GenericWindow();
        }

        void GenericWindow::Destroy()
        {
            
        }
    }
} // namespace Corgi
