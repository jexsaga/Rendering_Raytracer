#include "Mesh.h"

namespace mpbr
{

    void Mesh::addTriangle( const Triangle& triangle )
    {
        m_triangles.push_back( triangle );
    }

    uint32_t Mesh::triangleCount() const
    {
        return static_cast< uint32_t >( m_triangles.size() );
    }

    const Triangle& Mesh::triangle( uint32_t index ) const
    {
        return m_triangles[ index ];
    }

    const std::vector< Triangle >& Mesh::triangles() const
    {
        return m_triangles;
    }

    uint32_t Mesh::addVertex( const Vertex& vertex )
    {
        m_vertices.push_back( vertex );

        return static_cast< uint32_t >( m_vertices.size() - 1u );
    }

    const Vertex& Mesh::getVertex( uint32_t index ) const
    {
        return m_vertices[ index ];
    }

    const std::vector< Vertex >& Mesh::vertices() const
    {
        return m_vertices;
    }

}
