#pragma once

namespace Corgi
{
    namespace Core
    {
        struct Math
        {
            template <typename T>
            static constexpr T Max(const T a, const T b)
            {
                return (a >= b) ? a : b;
            }

            template <typename T>
            static T Max3(const T a, const T b, const T c)
            {
                return Max(a, Max(b, c));
            }
        };
    } // namespace Core
} // namespace Corgi