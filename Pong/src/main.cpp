#include <engine/engine.h>
#include <iostream>
engine myEngine;

Position posOfPlayer1(-0.8, 0.0, 0.2, "quad");
quad Player1(posOfPlayer1, Red, &myEngine, "Player1");

Position posOfPlayer2(0.8, 0.0, 0.2, "quad");
quad Player2(posOfPlayer2, Blue, &myEngine, "Player2");

Position posOfBall(0.0,0.0,0.1f,"quad");
quad Ball(posOfBall, Green, &myEngine, "Ball");

float speed = 2;
float speedOfBallX = 0.5;
float speedOfBallY = 0.7;

bool canBounce = true;

void engine::Start(){
    myEngine.DrawQuad(Player1);
    myEngine.DrawQuad(Player2);
    myEngine.DrawQuad(Ball);
}
float elapsedTime = 0;
void timeOfBounce(){
    elapsedTime += myEngine.deltaTime;
    if(elapsedTime >= 0.1f){
        elapsedTime = 0.1f;
        canBounce = true;
    }
}
void topColl(){
    if(canBounce){
        speedOfBallY*=-1;
        canBounce = false;
        elapsedTime = 0;
    }
}
void boxColl(){
    if(canBounce){ 
        speedOfBallX *= -1;
        canBounce = false;
        elapsedTime = 0;
    }
}
void engine::Update(){ 

    timeOfBounce();
    myEngine.checkForQuadCollision(Ball, Player2, &boxColl, &topColl);
    myEngine.checkForQuadCollision(Ball, Player1, &boxColl, &topColl);
    
    Ball.changePosition(speedOfBallX * deltaTime, speedOfBallY * deltaTime);

    if(myEngine.KeyBeingPressed(W)){
        Player1.changePosition(0, speed * deltaTime);
    }
    if(myEngine.KeyBeingPressed(S)){
        Player1.changePosition(0, -speed * deltaTime);
    }

    if(myEngine.KeyBeingPressed(UP)){
        Player2.changePosition(0, speed * deltaTime);
    }
    if(myEngine.KeyBeingPressed(DOWN)){
        Player2.changePosition(0, -speed * deltaTime);
    }
}

int main()
{
    myEngine.RunGame();
    return 0;
}