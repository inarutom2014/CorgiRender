#pragma once

#include "../CoreTypes.h"

namespace Corgi
{
    namespace Core
    {
        struct Color
        {
        public:
#if PLATFORM_LITTLE_ENDIAN
#ifdef _MSC_VER
            // Win32 x86
            union {
                struct
                {
                    uint8 B, G, R, A;
                };
                uint32 AlignDummy;
            };
#else
            uint8 B GCC_ALIGN(4);
            unit8 G, R, A;
#endif
#else
            union {
                struct
                {
                    uint8 A, R, G, B;
                    uint32 AlignDummy;
                };
            };

#endif
            Color(uint8 r, uint8 g, uint8 b, uint8 a = 255)
#if PLATFORM_LITTLE_ENDIAN
                : B(b), G(g), R(r), A(a)
#else
                : A(a), R(r), G(g), B(b)
#endif
            {
            }

            Color()
            {
                R = G = B = A = 0;
            }
        };

        struct LinearColor
        {
            float R, G, B, A;

            LinearColor()
                : R(0), G(0), B(0), A(0)
            {
            }

            LinearColor(float r, float g, float b, float a)
                : R(r), G(g), B(b), A(a)
            {
            }

            Color ToRGBE() const;
        };
    } // namespace Core
} // namespace Corgi