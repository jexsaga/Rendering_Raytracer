file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    *.h
    *.cpp
)

add_library(mpbr STATIC ${SOURCES})

target_compile_definitions(mpbr PUBLIC
    GLFW_INCLUDE_NONE
    IMGUI_IMPL_OPENGL_LOADER_GLAD
)

target_include_directories(mpbr PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Core
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Geometry
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Intersections
    ${CMAKE_CURRENT_SOURCE_DIR}/IO
    ${CMAKE_CURRENT_SOURCE_DIR}/CPU
    ${CMAKE_CURRENT_SOURCE_DIR}/Scenes
    ${Stb_INCLUDE_DIR}
)

target_link_libraries(mpbr PUBLIC
    glm::glm
    glfw
    glad::glad
    imgui::imgui
    assimp::assimp
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})
