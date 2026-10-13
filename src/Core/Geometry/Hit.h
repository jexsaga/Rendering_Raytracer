#pragma once

//------------------------------------------------------------
//
// MinimalPBR
//
// Hit
//
// Result of a ray-scene intersection.
//
//------------------------------------------------------------

#pragma once

#include <glm/glm.hpp>

#include <cstdint>
#include <limits>

namespace mpbr
{

    struct Hit
    {
        bool valid = false;

        float distance = std::numeric_limits<float>::max();

        glm::vec3 position = glm::vec3(0.0f);
        glm::vec3 normal = glm::vec3(0.0f);

        glm::vec2 barycentrics = glm::vec2(0.0f);

        uint32_t primitiveIndex = 0u;
        uint32_t materialIndex = 0u;
    };

}
