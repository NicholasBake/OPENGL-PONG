# pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <engine/Util/Position.h>
#include <iostream>
using namespace std;
class tri {
    public:
    Position Positionz;
    const char* Material;
    void drawTri(const char* material);
    tri(Position position, const char* mat){
        for (int i = 0; i < 9; i++)
        {
            Positionz.vertsCalculated[i] = position.vertsCalculated[i];
        }
        Material = mat;
        Positionz.size = position.size;
        Positionz.x = position.x;
        Positionz.y = position.y;
        drawTri(mat);
    }
};