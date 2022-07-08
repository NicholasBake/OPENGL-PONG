#pragma once
#include <engine/engine.h>
class engine;
class quad {
    public:
    Position tri1Pos;
    Position tri2Pos;
    GLFWwindow*window;
    Position position; 
    engine *Engine;
    const char* Material;
    std::string Name;
    void changePosition(float X, float Y);
    quad(Position pos, const char* material, engine *ENGINE, std::string name){

        position.x = pos.x;
        position.y = pos.y;
        position.size = pos.size;        

        tri1Pos.size = pos.size;
        tri1Pos.x = position.x;
        tri1Pos.y = position.y;
        
        tri2Pos.x = position.x;
        tri2Pos.y = position.y;
        tri2Pos.size = pos.size;        

        tri1Pos.changeType("triangleLeft");
        tri2Pos.changeType("triangleRight");
        
        Engine = ENGINE;
        Material = material;
        Name = name;
    }
};