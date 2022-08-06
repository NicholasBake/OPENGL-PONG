# pragma once
#include <engine/engine.h>
#include <engine/Util/Position.h>
using namespace std;
class engine;
class tri {
    public:
    float boundingBoxX;
    float boundingBoxY;
    Position Positionz;
    engine *Engine;
    const char* Material;
    std::string name;
    void drawTri(const char* material);
    void changePosition(float x = 0, float y = 0);
    tri(Position position, const char* mat, engine* ENGINE, std::string nam){
        for (int i = 0; i < 9; i++)
        {
            Positionz.vertsCalculated[i] = position.vertsCalculated[i];
        }
        Material = mat;
        Engine = ENGINE;
        Positionz.size = position.size;
        Positionz.x = position.x;
        Positionz.y = position.y;
        name = nam;
        boundingBoxX = 0;
        boundingBoxY = 0;
        drawTri(mat);
    }
};