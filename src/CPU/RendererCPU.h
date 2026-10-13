#pragma once

#include "Camera.h"
#include "Image.h"
#include "Scene.h"

#include <cstdint>

namespace mpbr
{

enum class RenderMode
{
    Color,
    Normal,
    Depth
};

class RendererCPU
{
public:

    RendererCPU() = default;

    void render( const Scene& scene, const Camera& camera, Image& image );

    void setMode( RenderMode mode );

private:

    void renderPixel( const Scene& scene, const Camera& camera, Image& image, uint32_t x, uint32_t y );

private:

    RenderMode m_mode = RenderMode::Color;
};

}
