#pragma once

#include "Mesh.h"
#include "Scene.h"
#include "Triangle.h"
#include "Material.h"

#include <glm/glm.hpp>

namespace mpbr
{

    class CornellBoxScene
    {
    public:

        static Scene create( float scale = 1.0f / 278.0f )
        {
            Scene scene;
            Mesh mesh;

            PointLight light;
            light.position = glm::vec3(0.0f, 0.8f, 2.5f);
            light.intensity = glm::vec3(1.5f);
            scene.addLight(light);

            PointLight light2;
            light2.position = glm::vec3(-0.5f, 0.1f, 2.5f);
            light2.intensity = glm::vec3(0.0, 0.0, 1.0);
            //scene.addLight(light2);

            Material white;
            white.baseColor = glm::vec3(0.8f);

            Material red;
            red.baseColor = glm::vec3(0.8f, 0.1f, 0.1f);

            Material green;
            green.baseColor = glm::vec3(0.1f, 0.8f, 0.1f);

            Material lightMaterial;
            lightMaterial.baseColor = glm::vec3(1.0f);
            lightMaterial.emission = glm::vec3(2.0f);

            const uint32_t whiteId = scene.addMaterial( white );
            const uint32_t redId = scene.addMaterial( red );
            const uint32_t greenId = scene.addMaterial( green );
            const uint32_t lightId = scene.addMaterial( lightMaterial );

            auto v = [ scale ]( float x, float y, float z )
            {
                return glm::vec3(
                    -( x - 278.0f ) * scale,
                     ( y - 274.4f ) * scale,
                    -( z - 900.0f ) * scale
                );
            };

            auto addQuad = [ &mesh, &v ](
                    const glm::vec3& a,
                    const glm::vec3& b,
                    const glm::vec3& c,
                    const glm::vec3& d,
                    uint32_t materialIndex)
            {
                Vertex vertexA;
                vertexA.position = v( a.x, a.y, a.z );

                Vertex vertexB;
                vertexB.position = v( b.x, b.y, b.z );

                Vertex vertexC;
                vertexC.position = v( c.x, c.y, c.z );

                Vertex vertexD;
                vertexD.position = v( d.x, d.y, d.z );

                const uint32_t indexA = mesh.addVertex( vertexA );
                const uint32_t indexB = mesh.addVertex( vertexB );
                const uint32_t indexC = mesh.addVertex( vertexC );
                const uint32_t indexD = mesh.addVertex( vertexD );

                Triangle triangle0;
                triangle0.vertex0 = indexA;
                triangle0.vertex1 = indexB;
                triangle0.vertex2 = indexC;
                triangle0.materialIndex = materialIndex;

                Triangle triangle1;
                triangle1.vertex0 = indexA;
                triangle1.vertex1 = indexC;
                triangle1.vertex2 = indexD;
                triangle1.materialIndex = materialIndex;

                mesh.addTriangle( triangle0 );
                mesh.addTriangle( triangle1 );
            };

            addQuad({ 552.8f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 559.2f }, { 549.6f, 0.0f, 559.2f }, whiteId);
            addQuad({ 343.0f, 548.8f, 227.0f }, { 343.0f, 548.8f, 332.0f }, { 213.0f, 548.8f, 332.0f }, { 213.0f, 548.8f, 227.0f }, lightId);
            addQuad({ 556.0f, 548.8f, 0.0f }, { 556.0f, 548.8f, 559.2f }, { 0.0f, 548.8f, 559.2f }, { 0.0f, 548.8f, 0.0f }, whiteId);
            addQuad({ 549.6f, 0.0f, 559.2f }, { 0.0f, 0.0f, 559.2f }, { 0.0f, 548.8f, 559.2f }, { 556.0f, 548.8f, 559.2f }, whiteId);
            addQuad({ 0.0f, 0.0f, 559.2f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 548.8f, 0.0f }, { 0.0f, 548.8f, 559.2f }, greenId);
            addQuad({ 552.8f, 0.0f, 0.0f }, { 549.6f, 0.0f, 559.2f }, { 556.0f, 548.8f, 559.2f }, { 556.0f, 548.8f, 0.0f }, redId);

            addQuad({ 130.0f, 165.0f, 65.0f }, { 82.0f, 165.0f, 225.0f }, { 240.0f, 165.0f, 272.0f }, { 290.0f, 165.0f, 114.0f }, whiteId);
            addQuad({ 290.0f, 0.0f, 114.0f }, { 290.0f, 165.0f, 114.0f }, { 240.0f, 165.0f, 272.0f }, { 240.0f, 0.0f, 272.0f }, whiteId);
            addQuad({ 130.0f, 0.0f, 65.0f }, { 130.0f, 165.0f, 65.0f }, { 290.0f, 165.0f, 114.0f }, { 290.0f, 0.0f, 114.0f }, whiteId);
            addQuad({ 82.0f, 0.0f, 225.0f }, { 82.0f, 165.0f, 225.0f }, { 130.0f, 165.0f, 65.0f }, { 130.0f, 0.0f, 65.0f }, whiteId);
            addQuad({ 240.0f, 0.0f, 272.0f }, { 240.0f, 165.0f, 272.0f }, { 82.0f, 165.0f, 225.0f }, { 82.0f, 0.0f, 225.0f }, whiteId);

            addQuad({ 423.0f, 330.0f, 247.0f }, { 265.0f, 330.0f, 296.0f }, { 314.0f, 330.0f, 456.0f }, { 472.0f, 330.0f, 406.0f }, whiteId);
            addQuad({ 423.0f, 0.0f, 247.0f }, { 423.0f, 330.0f, 247.0f }, { 472.0f, 330.0f, 406.0f }, { 472.0f, 0.0f, 406.0f }, whiteId);
            addQuad({ 472.0f, 0.0f, 406.0f }, { 472.0f, 330.0f, 406.0f }, { 314.0f, 330.0f, 456.0f }, { 314.0f, 0.0f, 456.0f }, whiteId);
            addQuad({ 314.0f, 0.0f, 456.0f }, { 314.0f, 330.0f, 456.0f }, { 265.0f, 330.0f, 296.0f }, { 265.0f, 0.0f, 296.0f }, whiteId);
            addQuad({ 265.0f, 0.0f, 296.0f }, { 265.0f, 330.0f, 296.0f }, { 423.0f, 330.0f, 247.0f }, { 423.0f, 0.0f, 247.0f }, whiteId);

            scene.addMesh( mesh );
            
            return scene;
        }
    };

}
