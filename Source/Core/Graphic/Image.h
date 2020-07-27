#pragma once
#include "../CoreTypes.h"

namespace Corgi
{
    namespace Core
    {
        class Image
        {
        public:
            enum class EImageFormat
            {
                LDR,
                HDR,
            };

            static Image* Create(int32 width, int32 height, int32 channels, EImageFormat foramt);
            static Image* Load(const ANSICHAR* fileName);
            virtual ~Image();

            void Save(const ANSICHAR* fileName);
            inline uint8* GetLdrBuffer() const { return m_ldrBuffer; }

        private:
            Image(int32 width, int32 height, int32 channels, EImageFormat format);

        private:
            EImageFormat m_format;
            int m_width;
            int m_height;
            int m_channels;
            uint8* m_ldrBuffer;
            float* m_hdrBuffer;
        };
    } // namespace Core
} // namespace Corgi