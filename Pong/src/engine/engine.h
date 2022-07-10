#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <engine/shaperenders/tri.h>
#include <engine/Util/Position.h>
#include <engine/Util/Colors.hpp>
#include <engine/Util/Keys.hpp>
#include <engine/shaperenders/quad.h>

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
class quad;
class tri;
class engine
{
    void DrawItems();
    void updateDeltaTime();
    public:
    float lastFrame;
    float deltaTime;
    static int currentKey;
    GLFWwindow *window;
    std::vector<tri> tris;
    static std::vector<int> KeysPressed;
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
    void DrawTriangle(tri* triangle = NULL);
    void DrawQuad(quad Quad);
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void Update();
    void Start();
};