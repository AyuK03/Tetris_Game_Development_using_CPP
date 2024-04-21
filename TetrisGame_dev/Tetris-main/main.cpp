#include "raylib.h"
#include "game.h"
using namespace std;

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if(currentTime-lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main(){
    Color darkPurple = {40, 0, 95, 255};
    InitWindow(300, 600, "Raylib Tetris Game by Ayushi_K");
    SetTargetFPS(60);                           // defines the frame rate so that game runs in the speed we want, if not define then it will run in the speed of computer
    Game game = Game();
    while(!WindowShouldClose())
    {   
        game.HandleInput();
        if(EventTriggered(0.25))
        {
            game.MoveBlockDown();
        }
        //game.MoveBlockDown();  // if added just within while loop block will drop very fast .. at speed of 60fps
        BeginDrawing();
        ClearBackground(darkPurple);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}