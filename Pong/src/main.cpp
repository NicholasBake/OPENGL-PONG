#include <engine/engine.h>
#include <iostream>
engine myEngine;
int main()
{
    Position pos(0.1f, 0, 0.2f, "Quad");
    quad myRect(pos, Green, &myEngine);

    Position Pos(-0.5f, 0.0f, 0.01f, "Quad");
    quad mySecondRect(Pos, Blue, &myEngine);

    Position posTri(0.0, 0.0, 0.1, "triangleLeft");
    tri myTriangle(posTri, Red);

    Position posTriad(0.0, 0.0, 0.1, "triangleRight");
    tri MyTriangle(posTriad, White);

    myEngine.DrawQuad(myRect);
    myEngine.DrawQuad(mySecondRect);
    myEngine.DrawTriangle(NULL, &myTriangle);
    myEngine.DrawTriangle(NULL, &MyTriangle);

    myEngine.RunGame();
    return 0;
}