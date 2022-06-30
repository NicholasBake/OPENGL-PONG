#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <engine/shaperenders/tri.h>
#include <engine/Util/Position.h>
#include <engine/Util/Colors.hpp>
#include <engine/shaperenders/quad.h>

#include <vector>
#include <iostream>
class quad;
class engine
{
    void DrawItems();
    public:
    GLFWwindow *window;
    vector<tri> tris;
    engine()
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        window = glfwCreateWindow(800, 600, "Pong", NULL, NULL);

        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
        }

        glfwMakeContextCurrent(window);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
        }

        glViewport(0, 0, 800, 600);

    }
    void RunGame();
    void DrawTriangle(float verts[9] = NULL, tri* triangle = NULL);
    void DrawQuad(quad Quad);
};