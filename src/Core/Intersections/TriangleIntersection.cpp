#include "TriangleIntersection.h"

#include <glm/glm.hpp>

#include <cmath>

namespace mpbr
{

bool TriangleIntersection::intersect(
    const Ray& ray,
    const Triangle& triangle,
    const std::vector< Vertex >& vertices,
    Hit& hit)
{
    return false;
}

}
