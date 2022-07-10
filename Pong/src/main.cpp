#include <engine/engine.h>
#include <iostream>
engine myEngine;

Position posOfPlayer1(-0.8, 0.0, 0.2, "quad");
quad Player1(posOfPlayer1, Red, &myEngine, "Player1");

Position posOfPlayer2(0.8, 0.0, 0.2, "quad");
quad Player2(posOfPlayer2, Blue, &myEngine, "Player2");

float speed = 2;

void engine::Start(){
    myEngine.DrawQuad(Player1);
    myEngine.DrawQuad(Player2);
}
void engine::Update(){
    
}

int main()
{
    myEngine.RunGame();
    return 0;
}