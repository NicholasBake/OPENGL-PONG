#include <engine/Util/Position.h>
void Position::CalcVector(std::string type, float size){

    if(type == "triangle" || type == "Triangle" || type == "tri" || type == "Tri"){
        // First vertice
        Position::vertsCalculated[0] = Position::x - size;
        Position::vertsCalculated[1] = Position::y - size;
        Position::vertsCalculated[2] = 0.0f;
        // Second vertice
        Position::vertsCalculated[3] = Position::x + size;
        Position::vertsCalculated[4] = Position::y - size;
        Position::vertsCalculated[5] = 0.0f;
        // Third vertice
        Position::vertsCalculated[6] = Position::x;
        Position::vertsCalculated[7] = Position::y + size;
        Position::vertsCalculated[8] = 0.0f;
    }
    if(type == "triangleLeft" || type == "TriangleLeft" || type == "triLeft" || type == "TriLeft"){
        // First vertice
        Position::vertsCalculated[0] = Position::x - size;
        Position::vertsCalculated[1] = Position::y - size;
        Position::vertsCalculated[2] = 0.0f;
        // Second vertice
        Position::vertsCalculated[3] = Position::x + size;
        Position::vertsCalculated[4] = Position::y - size;
        Position::vertsCalculated[5] = 0.0f;
        // Third vertice
        Position::vertsCalculated[6] = Position::x - size;
        Position::vertsCalculated[7] = Position::y + size;
        Position::vertsCalculated[8] = 0.0f;
    }
    if(type == "triangleRight" || type == "TriangleRight" || type == "triRight" || type == "TriRight"){
        // First vertice
        Position::vertsCalculated[0] = Position::x + size;
        Position::vertsCalculated[1] = Position::y + size;
        Position::vertsCalculated[2] = 0.0f;
        // Second vertice
        Position::vertsCalculated[3] = Position::x + size;
        Position::vertsCalculated[4] = Position::y - size;
        Position::vertsCalculated[5] = 0.0f;
        // Third vertice
        Position::vertsCalculated[6] = Position::x - size;
        Position::vertsCalculated[7] = Position::y + size;
        Position::vertsCalculated[8] = 0.0f;
    }
}
void Position::changeType(std::string type){
    if(type == ""){
        Position::TypeofTri = Position::TypeofTri;
    }
    else{
        Position::TypeofTri = type;
    }
    Position::CalcVector(Position::TypeofTri, Position::size);
}