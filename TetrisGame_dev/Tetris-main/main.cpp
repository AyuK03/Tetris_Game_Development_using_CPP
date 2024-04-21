#include "raylib.h"
#include "game.h"
#include "colors.h"
#include <iostream>
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
    InitWindow(500, 620, "Raylib Tetris Game by Ayushi_K"); // created an offset to have an UI
    //InitWindow(300, 600, "Raylib Tetris Game by Ayushi_K");   //This size matched exactly with the grid dimensions
    
    Font font = LoadFontEx("Fonts/MightySouly.ttf", 64, 0, 0);
    Font font2 = LoadFontEx("Fonts/HalloweenSlime.otf", 24, 0, 0);
    SetTargetFPS(60);                           // defines the frame rate so that game runs in the speed we want, if not define then it will run in the speed of computer
    Game game = Game();
    while(!WindowShouldClose())
    {   
        game.HandleInput();
        if(EventTriggered(0.28))
        {
            game.MoveBlockDown();
        }
        //game.MoveBlockDown();  // if added just within while loop block will drop very fast .. at speed of 60fps
        BeginDrawing();
        ClearBackground(darkPurple);
        DrawTextEx(font, "Score", {365, 20}, 38, 2, WHITE);

        DrawTextEx(font, "Next", {370, 180}, 38, 2, WHITE);
        DrawRectangleRounded({320, 220, 170, 180}, 0.3, 6, lightBlue);
        
        char scoreTest[10];
        sprintf(scoreTest,"%d",game.score);
        Vector2 textSize = MeasureTextEx(font, scoreTest, 38, 2);
        DrawTextEx(font, scoreTest , {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

        if(game.gameOver)
        {
            DrawTextEx(font2, "GAME OVER!", {330, 460}, 30, 2, WHITE);
        }

        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}