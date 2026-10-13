#include "Scene.h"

#include "TriangleIntersection.h"

#include <utility>

namespace mpbr
{

    void Scene::addMesh( const Mesh& mesh )
    {
        const uint32_t baseVertex = static_cast< uint32_t >( m_vertices.size() );

        m_vertices.insert( m_vertices.end(), mesh.vertices().begin(), mesh.vertices().end() );

        for ( const Triangle& localTriangle : mesh.triangles() )
        {
            Triangle globalTriangle = localTriangle;
            globalTriangle.vertex0 += baseVertex;
            globalTriangle.vertex1 += baseVertex;
            globalTriangle.vertex2 += baseVertex;

            m_triangles.push_back( globalTriangle );
        }

        m_meshes.push_back( mesh );
    }

    uint32_t Scene::meshCount() const
    {
        return static_cast< uint32_t >( m_meshes.size() );
    }

    const Mesh& Scene::mesh( uint32_t index ) const
    {
        return m_meshes[ index ];
    }

    const std::vector< Mesh >& Scene::meshes() const
    {
        return m_meshes;
    }

    const std::vector< Vertex >& Scene::vertices() const
    {
        return m_vertices;
    }

    const std::vector< Triangle >& Scene::triangles() const
    {
        return m_triangles;
    }

    const Vertex& Scene::vertex( uint32_t index ) const
    {
        return m_vertices[ index ];
    }

    const Triangle& Scene::triangle( uint32_t index ) const
    {
        return m_triangles[ index ];
    }

    uint32_t Scene::addMaterial( const Material& material )
    {
        m_materials.push_back( material );

        return static_cast< uint32_t >( m_materials.size() - 1 );
    }

    const Material& Scene::material( uint32_t index ) const
    {
        return m_materials[ index ];
    }

    const std::vector< Material >& Scene::materials() const
    {
        return m_materials;
    }

    uint32_t Scene::addLight( const PointLight& light )
    {
        m_lights.push_back( light );

        return static_cast< uint32_t >( m_lights.size() - 1 );
    }

    const PointLight& Scene::light( uint32_t index ) const
    {
        return m_lights[ index ];
    }

    const std::vector<PointLight>& Scene::lights() const
    {
        return m_lights;
    }

    bool Scene::intersect( const Ray& ray, Hit& hit ) const
    {
        uint32_t primitiveIndex = 0;

        for ( const Mesh& mesh : m_meshes )
        {
            for ( const Triangle& triangle : mesh.triangles() )
            {
                const bool intersect = TriangleIntersection::intersect( ray, triangle, m_vertices, hit );
                if ( intersect )
                {
                    hit.primitiveIndex = primitiveIndex;
                }

                ++primitiveIndex;
            }
        }

        return hit.valid;
    }

}
