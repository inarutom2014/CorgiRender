#pragma once

#include "../CoreTypes.h"

namespace Corgi
{
    namespace Core
    {
        namespace Graphic
        {
            class FrameBuffer
            {
            public:
                FrameBuffer(int32 width, int32 height);
                virtual ~FrameBuffer();
                void ClearColor();
                void ClearDepth(float depth);

            private:
                int32 m_width;
                int32 m_height;
                uint8 *m_colorBuffer;
                float *depthBuffer;
            };
        } // namespace Graphic
    }     // namespace Core
} // namespace Corgi