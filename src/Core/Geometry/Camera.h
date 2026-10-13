#pragma once

//------------------------------------------------------------
//
// MinimalPBR
//
// Camera
//
// Perspective camera.
//
//------------------------------------------------------------

#include "Ray.h"

#include <glm/glm.hpp>

namespace mpbr
{

    class Camera
    {
        public:
            Ray generateRay(const glm::vec2& uv, float aspectRatio) const;

            glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
            glm::vec3 forward = glm::vec3(0.0f, 0.0f, 0.0f);
            glm::vec3 right = glm::vec3(0.0f, 0.0f, 0.0f);
            glm::vec3 up = glm::vec3(0.0f, 0.0f, 0.0f);

            float fovY = glm::radians(45.0f);
    };

}
