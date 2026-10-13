#include "Image.h"

namespace mpbr
{

    Image::Image( uint32_t width, uint32_t height )
        :
        m_width( width ),
        m_height( height ),
        m_pixels( width * height, glm::vec3( 0.0f ) )
    {
    }

    glm::vec3& Image::pixel( uint32_t x, uint32_t y )
    {
        return m_pixels[ y * m_width + x ];
    }

    const glm::vec3& Image::pixel( uint32_t x, uint32_t y ) const
    {
        return m_pixels[ y * m_width + x ];
    }

    uint32_t Image::width() const
    {
        return m_width;
    }

    uint32_t Image::height() const
    {
        return m_height;
    }

}
