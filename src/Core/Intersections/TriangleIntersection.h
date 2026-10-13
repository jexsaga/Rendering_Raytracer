#pragma once

#include "Hit.h"
#include "Ray.h"
#include "Triangle.h"
#include "Vertex.h"

#include <vector>

namespace mpbr
{

class TriangleIntersection
{
public:

    static bool intersect(
        const Ray& ray,
        const Triangle& triangle,
        const std::vector< Vertex >& vertices,
        Hit& hit);
};

}
