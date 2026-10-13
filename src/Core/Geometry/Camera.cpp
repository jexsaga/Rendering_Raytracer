#include "Camera.h"

#include <glm/gtc/constants.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace mpbr
{

    //------------------------------------------------------------

    Ray Camera::generateRay( const glm::vec2& uv, float aspectRatio ) const
    {
        Ray ray;

        ray.origin = position;

        float pX = uv.x * tan(fovY / 2);      //  * 3.1415 / 180
        float pY = uv.y * tan(fovY / 2);                    // * 3.1415 / 180
        ray.direction = glm::vec3(pX, pY, -1) - ray.origin;
        ray.direction = glm::normalize(ray.direction);

        return ray;
    }
}
