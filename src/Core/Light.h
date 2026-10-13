#pragma once

#include <glm/glm.hpp>

namespace mpbr
{

struct PointLight
{
    glm::vec3 position = glm::vec3(0.0f);
    glm::vec3 intensity = glm::vec3(1.0f);
};

}
