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
    glm::vec3 v0v1 = vertices[triangle.vertex1].position - vertices[triangle.vertex0].position;
    glm::vec3 v1v2 = vertices[triangle.vertex2].position - vertices[triangle.vertex1].position;
    glm::vec3 v0v2 = vertices[triangle.vertex2].position - vertices[triangle.vertex0].position;
    
    glm::vec3 N = glm::cross(v0v1, v0v2);

    // check if parallel
    float NdotRayDirection = glm::dot(N, ray.direction);
    if (fabs(NdotRayDirection) < 0.00001)
        return false;

    float d = - glm::dot(N, vertices[triangle.vertex0].position);
    float t = -(glm::dot(N, ray.origin) + d) / NdotRayDirection;

    // Check if the triangle is behind the ray
    if (t < 0) return false;

    glm::vec3 P = ray.pointAt(t);
    
    glm::vec3 v0p = P - vertices[triangle.vertex0].position;
    glm::vec3 v1p = P - vertices[triangle.vertex1].position;
    glm::vec3 v2p = P - vertices[triangle.vertex2].position;

    // check sideness of P w.r.t edge v0v1
    if (glm::dot(N, glm::cross(v0v1, v0p)) < 0) return false;
    // check sideness of P w.r.t edge v1v2
    if (glm::dot(N, glm::cross(v1v2, v1p)) < 0) return false;
    // check sideness of P w.r.t edge v0v2
    if (glm::dot(N, glm::cross(v0v2, v2p)) < 0) return false;

    return true;
}

}
