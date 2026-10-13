#pragma once

//------------------------------------------------------------
//
// MinimalPBR
//
// Image
//
// CPU image.
//
//------------------------------------------------------------

#pragma once

#include <glm/glm.hpp>

#include <cstdint>
#include <vector>

namespace mpbr
{

    class Image
    {
    public:

        Image( uint32_t width, uint32_t height );

    public:

        glm::vec3& pixel( uint32_t x, uint32_t y );

        const glm::vec3& pixel( uint32_t x, uint32_t y ) const;

    public:

        uint32_t width() const;
        uint32_t height() const;

    private:

        uint32_t m_width = 0;
        uint32_t m_height = 0;

        std::vector< glm::vec3 > m_pixels;
    };

}

