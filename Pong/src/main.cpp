#include <engine/engine.h>
#include <iostream>
engine myEngine;
int main()
{
    Position pos(0.1f, 0, 0.2f, "Quad");
    quad myRect(pos, Green, &myEngine, "MyRect");

    Position Pos(-0.5f, 0.0f, 0.1f, "Quad");
    quad mySecondRect(Pos, Blue, &myEngine, "MyRectangle"); 

    Position posofTriangle(0.0, -0.5, 0.4, "Triangle");
    tri myTriangle(posofTriangle, White, &myEngine, "TheTriangle");

    myEngine.DrawQuad(myRect);
    myEngine.DrawQuad(mySecondRect);
    myEngine.DrawTriangle(&myTriangle);

    mySecondRect.changePosition(0.0f, 0.0);
    myRect.changePosition(-0.2f,0.1f);
    myTriangle.changePosition(0.5, 0.0);
    myEngine.RunGame();
    return 0;
}