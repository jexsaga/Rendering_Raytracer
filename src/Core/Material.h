#pragma once

#include <glm/glm.hpp>

#include <cstdint>
#include <limits>
    
namespace mpbr
{

    struct Material
    {
        glm::vec3 baseColor = glm::vec3(1.0f);
        glm::vec3 emission = glm::vec3(0.0f);
    };

}
