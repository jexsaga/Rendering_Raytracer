#include "ImageIO.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

#include <algorithm>
#include <cstdint>
#include <vector>

namespace mpbr
{

    bool ImageIO::save( const Image& image, const std::filesystem::path& filename )
    {
        if ( filename.extension() == ".png" )
            return savePNG( image, filename );

        return false;
    }

    bool ImageIO::savePNG( const Image& image, const std::filesystem::path& filename )
    {
        std::vector< uint8_t > pixels8;
        pixels8.resize( image.width() * image.height() * 3 );

        for ( uint32_t y = 0; y < image.height(); ++y )
        {
            for ( uint32_t x = 0; x < image.width(); ++x )
            {
                const glm::vec3 color = image.pixel( x, y );

                const uint32_t index = 3 * ( y * image.width() + x );

                pixels8[ index + 0 ] = toByte( color.r );
                pixels8[ index + 1 ] = toByte( color.g );
                pixels8[ index + 2 ] = toByte( color.b );
            }
        }

        return stbi_write_png(
            filename.string().c_str(),
            int( image.width() ),
            int( image.height() ),
            3,
            pixels8.data(),
            int( image.width() * 3 ) ) != 0;
    }

    uint8_t ImageIO::toByte( float value )
    {
        value = std::clamp( value, 0.0f, 1.0f );

        return static_cast< uint8_t >( 255.0f * value );
    }

}
