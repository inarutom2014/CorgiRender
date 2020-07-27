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
            virtual void DrawBuffer();
        };
    } // namespace Core
} // namespace Corgi