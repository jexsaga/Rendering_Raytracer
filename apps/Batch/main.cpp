#include "Image.h"
#include "ImageIO.h"
#include "RendererCPU.h"
#include "Camera.h"
#include "CornellBoxScene.h"

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

#include <iostream>

int main()
{
    mpbr::Scene scene = mpbr::CornellBoxScene::create();
    std::cout
        << "Cornell vertices  : "
        << scene.vertices().size()
        << '\n'
        << "Cornell triangles : "
        << scene.triangles().size()
        << '\n';

    mpbr::Camera camera;
    camera.position = glm::vec3( 0.0f, 0.0f, 6.0f );
    camera.forward = glm::vec3( 0.0f, 0.0f, -1.0f );
    camera.right = glm::vec3( 1.0f, 0.0f, 0.0f );
    camera.up = glm::vec3( 0.0f, 1.0f, 0.0f );
    camera.fovY = glm::radians( 45.0f );

    mpbr::Image image( 800, 600 );

    mpbr::RendererCPU renderer;
    renderer.setMode(
        mpbr::RenderMode::Color );
        //mpbr::RenderMode::Depth );
        //mpbr::RenderMode::Normal );

    renderer.render(
        scene,
        camera,
        image);

    if ( ! mpbr::ImageIO::save( image, "output.png" ) )
    {
        std::cerr << "Failed to save output.png\n";

        return 1;
    }

    std::cout << "Saved output.png\n";

    return 0;
}
