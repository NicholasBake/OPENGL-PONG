#include <engine/engine.h>

void engine::RunGame()
{
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2,0.2,0.2,1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
        DrawItems();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}
void engine::DrawTriangle(tri* triangle)
{
    tri Triangle(triangle->Positionz, triangle->Material, triangle->Engine, triangle->name);
    this->tris.push_back(Triangle);
    return;
}
void engine::DrawQuad(quad quad)
{
    tri Triangle1(quad.tri1Pos, quad.Material, quad.Engine, quad.Name);
    tri Triangle2(quad.tri2Pos, quad.Material, quad.Engine, quad.Name);
    DrawTriangle(&Triangle1);
    DrawTriangle(&Triangle2);
    return;
}
void engine::DrawItems()
{
    for (int i = 0; i < engine::tris.size(); i++)
    {
        this->tris[i].drawTri(tris[i].Material);
    }
}