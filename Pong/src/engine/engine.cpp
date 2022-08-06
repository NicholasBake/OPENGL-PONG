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
}
void engine::checkForQuadCollision(quad objOne, quad objTwo,  std::function<void()> onCollision, std::function<void()> onTopCollision){
    objOne.boundingBoxX = objOne.position.x + objOne.position.size;
    objOne.boundingBoxY = objOne.position.y - objOne.position.size;

    objTwo.boundingBoxX = objTwo.position.x + objTwo.position.size;
    objTwo.boundingBoxY = objTwo.position.y - objTwo.position.size;

    if(objOne.boundingBoxX >= 1.0 || objOne.boundingBoxX - objOne.position.size * 2 <= -1.0 ){
        onCollision();
    }
    if(objOne.boundingBoxY <= -1.0 || objOne.boundingBoxY + objOne.position.size * 2 >= 1.0){
        onTopCollision();
    }
    if(objOne.boundingBoxX <= objTwo.boundingBoxX && objOne.boundingBoxX >= objTwo.boundingBoxX - objTwo.position.size * 2 || objOne.boundingBoxX - objOne.position.size * 2 >= objTwo.boundingBoxX - objTwo.position.size * 2 && objOne.boundingBoxX - objOne.position.size * 2 <= objTwo.boundingBoxX){
        if(objOne.boundingBoxY >= objTwo.boundingBoxY && objOne.boundingBoxY <= objTwo.boundingBoxY + objTwo.position.size * 2 || objOne.boundingBoxY + objOne.position.size * 2 >= objTwo.boundingBoxY && objOne.boundingBoxY + objOne.position.size * 2 <= objTwo.boundingBoxY + objTwo.position.size * 2){
            onCollision();
        }
    }
}