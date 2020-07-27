#pragma once

namespace Corgi
{
    namespace Core
    {
        class GenericWindow
        {
        public:
            GenericWindow();
            virtual ~GenericWindow();

            static GenericWindow* Create(int width, int height);
            virtual void Destroy();
        };
    }
}