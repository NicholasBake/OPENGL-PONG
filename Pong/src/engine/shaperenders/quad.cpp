#include <engine/shaperenders/quad.h>
#include <algorithm>
void quad::changePosition(float X, float Y){
    for (int i = 0; i < quad::Engine->tris.size(); i++)
    {
        if(quad::Engine->tris[i].name == this->Name){
            quad::Engine->tris.erase(quad::Engine->tris.begin() + i);
            quad::Engine->tris.erase(quad::Engine->tris.begin() + i);
        }
    }
    
    quad::position.x += X;
    quad::position.y += Y;
    quad newQuadToDraw(quad::position, quad::Material, quad::Engine, quad::Name);
    quad::Engine->DrawQuad(newQuadToDraw);
}