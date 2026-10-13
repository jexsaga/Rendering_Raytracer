#pragma once

//------------------------------------------------------------
//
// MinimalPBR
//
// Ray
//
// A ray is defined by an origin and a direction.
//
// Equation:
//
//      P(t) = O + t D
//
//------------------------------------------------------------

#pragma once

#include <glm/glm.hpp>

namespace mpbr
{

    struct Ray
    {
        glm::vec3 origin;
        glm::vec3 direction;

        glm::vec3 pointAt(float t) const
        {
            return origin + t * direction;
        };
    };

}
