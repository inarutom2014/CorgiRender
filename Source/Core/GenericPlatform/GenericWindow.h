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
            virtual void Destroy();
        };
    } // namespace Core
} // namespace Corgi