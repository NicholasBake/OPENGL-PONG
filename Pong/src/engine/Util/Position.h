#include <string>
#pragma once
class Position {
    public: 
    float x, y, size;
    float vertsCalculated[9];
    std::string TypeofTri;
    void CalcVector(std::string type, float Size);
    void changeType(std::string type = "");
    Position(float X = 0, float Y = 0, float Size = 0.5f,std::string Type = "triangle"){
        x = X;
        y = Y;
        size = Size;
        TypeofTri = Type;
        
        if(Type != "quad" || Type != "Quad" || Type != "rectangle" || Type != "Rectangle" || Type != "rect" || Type != "Rect"){
            CalcVector(TypeofTri, size);
        }
    }
};