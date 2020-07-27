#include "Color.h"
#include "MathUtility.h"

namespace Corgi
{
    namespace Core
    {
        Color LinearColor::ToRGBE() const
        {
            const float primary = Math::Max3(R,G,B);
            Color color;
            if (primary < 1E-32f)
            {
                
            }
            return color;
        }
    } // namespace Core
} // namespace Corgi