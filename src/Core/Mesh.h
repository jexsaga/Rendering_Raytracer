#pragma once

#include "Triangle.h"
#include "Vertex.h"

#include <cstdint>
#include <vector>

namespace mpbr
{

    class Mesh
    {
    public:

        void addTriangle( const Triangle& triangle );
        uint32_t triangleCount() const;
        const Triangle& triangle( uint32_t index ) const;
        const std::vector< Triangle >& triangles() const;

        uint32_t addVertex( const Vertex& vertex );
        const Vertex& getVertex( uint32_t index ) const;
        const std::vector< Vertex >& vertices() const;

    private:

        std::vector< Triangle > m_triangles;

        std::vector< Vertex > m_vertices;
    };

}
