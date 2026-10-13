#pragma once

#include "Image.h"

#include <filesystem>

namespace mpbr
{

    class ImageIO
    {
    public:

        static bool save( const Image& image, const std::filesystem::path& filename );

    private:

        static bool savePNG( const Image& image, const std::filesystem::path& filename );

        static uint8_t toByte( float value );
    };

}
