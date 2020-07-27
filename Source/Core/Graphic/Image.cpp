#include "Image.h"
#include <cstring>

namespace Corgi
{
    namespace Core
    {
        Image *Image::Create(int32 width, int32 height, int32 channels, EImageFormat format)
        {
            return new Image(width, height, channels, format);
        }

        Image *Image::Load(const ANSICHAR *fileName)
        {
            //TODO
            return nullptr;
        }

        Image::~Image()
        {
            if (m_ldrBuffer != nullptr)
            {
                delete[] m_ldrBuffer;
                m_ldrBuffer = nullptr;
            }
            if (m_hdrBuffer != nullptr)
            {
                delete[] m_hdrBuffer;
                m_hdrBuffer = nullptr;
            }
        }

        void Image::Save(const ANSICHAR *fileName)
        {
            
        }

        Image::Image(int32 width, int32 height, int32 channels, EImageFormat format)
            : m_width(width), m_height(height), m_channels(channels), m_format(format), m_ldrBuffer(nullptr), m_hdrBuffer(nullptr)
        {
            CORGI_CHECK(width > 0 && height > 0 && channels > 0);
            int numElements = width * height * channels;
            switch (format)
            {
            case EImageFormat::LDR:
            {
                const int32 size = sizeof(uint8) * numElements;
                m_ldrBuffer = new uint8[numElements];
                memset(m_ldrBuffer, 0, size);
                break;
            }
            case EImageFormat::HDR:
            {
                const int32 size = sizeof(float) * numElements;
                m_hdrBuffer = new float[numElements];
                memset(m_hdrBuffer, 0, size);
                break;
            }
            default:
                break;
            }
        }

    } // namespace Core
} // namespace Corgi