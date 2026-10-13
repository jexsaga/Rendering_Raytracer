#include "RendererCPU.h"

#include "Ray.h"
#include "Hit.h"
#include "Material.h"

#include "TriangleIntersection.h"

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
        return glm::vec3( 1.f );
    }

    //------------------------------------------------------------

    void RendererCPU::render( const Scene& scene, const Camera& camera, Image& image )
    {
        for (int x = 0; x < image.width(); x++)
        {
            for (int y = 0; y < image.height(); y++)
            {
                renderPixel(scene, camera, image, x, y);
            }
        }
    }

    //------------------------------------------------------------

    void RendererCPU::renderPixel( const Scene& scene, const Camera& camera, Image& image, uint32_t x, uint32_t y )
    {
        glm::vec3 radiance = glm::vec3( 0.f );

        float aspectRatio = image.width() / image.height();
        glm::vec2 uv;
        uv.x = 2 * (x + 0.5) - 1 * aspectRatio;
        uv.y = 1 - 2 * (y + 0.5);

        Ray ray = camera.generateRay(uv, aspectRatio);

        Hit closest;
        closest.distance = std::numeric_limits<float>::max();
        bool found = false;

        for (const Mesh& mesh : scene.meshes())
        {
            for (const Triangle& tri : mesh.triangles())
            {
                Hit hit;
                if (TriangleIntersection::intersect(ray, tri, mesh.vertices(), hit)
                    && hit.distance < closest.distance)
                {
                    closest = hit;
                    found = true;
                }
            }
        }

        if (found)
            radiance = glm::vec3(1.f);

        image.pixel(x, y) = radiance;
    }

    //------------------------------------------------------------

    void RendererCPU::setMode( RenderMode mode )
    {
        m_mode = mode;
    }

}
