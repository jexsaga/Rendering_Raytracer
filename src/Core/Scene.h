#pragma once

#include "Mesh.h"
#include "Ray.h"
#include "Hit.h"
#include "Material.h"
#include "Light.h"

#include "Triangle.h"
#include "Vertex.h"

#include <cstdint>
#include <vector>

namespace mpbr
{

    class Scene
    {
    public:

        void addMesh( const Mesh& mesh );
        uint32_t meshCount() const;
        const Mesh& mesh( uint32_t index ) const;
        const std::vector< Mesh >& meshes() const;

        const std::vector< Vertex >& vertices() const;
        const Vertex& vertex( uint32_t index ) const;

        const std::vector< Triangle >& triangles() const;
        const Triangle& triangle( uint32_t index ) const;

        uint32_t addMaterial(const Material& material);
        const Material& material(uint32_t index) const;
        const std::vector< Material >& materials() const;

        uint32_t addLight(const PointLight& light);
        const PointLight& light(uint32_t index) const;
        const std::vector< PointLight >& lights() const;

        bool intersect( const Ray& ray, Hit& hit ) const;

    private:

        std::vector< Mesh > m_meshes;

        std::vector< Vertex > m_vertices;
        std::vector< Triangle > m_triangles;
        
        std::vector< Material > m_materials;

        std::vector< PointLight > m_lights;

    };

}
