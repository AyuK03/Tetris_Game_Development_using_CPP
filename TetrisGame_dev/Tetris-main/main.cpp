#include "raylib.h"
#include "game.h"

using namespace std;

int main(){
    Color darkPurple = {40, 0, 95, 255};
    InitWindow(300, 600, "Raylib Tetris");
    SetTargetFPS(60);                           // defines the frame rate so that game runs in the speed we want, if not define then it will run in the speed of computer
    Game game = Game();
    while(!WindowShouldClose())
    {   
        game.HandleInput();
        BeginDrawing();
        ClearBackground(darkPurple);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}