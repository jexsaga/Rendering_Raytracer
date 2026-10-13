#pragma once

#include <glm/glm.hpp>

#include <cstdint>

namespace mpbr
{

struct Triangle
{
	uint32_t vertex0 = 0u;
	uint32_t vertex1 = 0u;
	uint32_t vertex2 = 0u;

	uint32_t materialIndex = 0u;
};

}
