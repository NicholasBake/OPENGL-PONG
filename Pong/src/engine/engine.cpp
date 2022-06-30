#include <engine/engine.h>

void engine::RunGame()
{
    while (!glfwWindowShouldClose(window))
    {
        DrawItems();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}
void engine::DrawTriangle(float verts[9], tri* triangle)
{
    if(triangle != 0){
        tri Triangle(triangle->Positionz, triangle->Material);
        this->tris.push_back(Triangle);
        return;
    }
    
    tri newTri(triangle->Positionz, triangle->Material);
    this->tris.push_back(newTri);
    
}
void engine::DrawQuad(quad quad)
{
    tri Triangle1(quad.tri1Pos, quad.Material);
    tri Triangle2(quad.tri2Pos, quad.Material);
    DrawTriangle(NULL, &Triangle1);
    DrawTriangle(NULL, &Triangle2);
    return;
}
void engine::DrawItems()
{
    for (int i = 0; i < engine::tris.size(); i++)
    {
        this->tris[i].drawTri(tris[i].Material);
    }
}