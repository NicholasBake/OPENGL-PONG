#include <engine/engine.h>

int engine::currentKey;
std::set<int> engine::KeysPressed;

void engine::RunGame()
{
    glfwSetKeyCallback(window, keyCallback);
    Start();
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2,0.2,0.2,1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
        glfwPollEvents();
        updateDeltaTime();
        DrawItems();
        Update();
        glfwSwapBuffers(window);
        
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
void engine::updateDeltaTime(){
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}
bool engine::KeyBeingPressed(int key){
    std::set<int>::iterator iter;
    iter = engine::KeysPressed.find(key);
    if(iter != engine::KeysPressed.end()){
        return true;
    }
    else{
        return false;
    }
}
void engine::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
    currentKey = key;
    if(action == GLFW_RELEASE){
        engine::KeysPressed.erase(currentKey);
        return;
    }
    engine::KeysPressed.insert(currentKey);
    std::cout << KeysPressed.size() << endl;
}