#include "RendererCPU.h"

#include "Ray.h"
#include "Hit.h"
#include "Material.h"

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

namespace mpbr
{

    //------------------------------------------------------------

    glm::vec3 evaluatePointLight(
        const mpbr::Scene& scene,
        const mpbr::Ray& viewRay,
        const mpbr::Hit& hit,
        const mpbr::Material& material,
        const mpbr::PointLight& light )
    {
        glm::vec3( 1.f );
    }

    //------------------------------------------------------------

    void RendererCPU::render( const Scene& scene, const Camera& camera, Image& image )
    {
        //renderPixel( scene, camera, image, x, y );
    }

    //------------------------------------------------------------

    void RendererCPU::renderPixel( const Scene& scene, const Camera& camera, Image& image, uint32_t x, uint32_t y )
    {
        glm::vec3 radiance = glm::vec3( 0.f );
        image.pixel( x, y ) = radiance;
    }

    //------------------------------------------------------------

    void RendererCPU::setMode( RenderMode mode )
    {
        m_mode = mode;
    }

}
