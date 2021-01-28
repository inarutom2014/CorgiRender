#pragma once

namespace Corgi
{
    namespace Core
    {
        class GenericWindow
        {
        public:
            GenericWindow();
			virtual bool ShouldClose() const { return true; }
            virtual ~GenericWindow();
            virtual void DrawBuffer();
        };
    } // namespace Core
} // namespace Corgi