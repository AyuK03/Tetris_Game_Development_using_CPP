#include <iostream>
#include "raylib.h"
#include "grid.h"
#include "blocks.cpp"

using namespace std;

int main(){
    Color darkPurple = {40, 0, 95, 255};
    InitWindow(300, 600, "Raylib Tetris");
    SetTargetFPS(60);                           // defines the frame rate so that game runs in the speed we want, if not define then it will run in the speed of computer
    
    Grid grid = Grid();
    grid.Print();

    LBlock block = LBlock();
    TBlock block2 = TBlock();



    /*
    // testing cell colors
    grid.grid[0][0] = 1;
    grid.grid[3][5] = 4;
    grid.grid[15][8] = 7;
    grid.grid[10][16] = 2;
    grid.grid[5][19] = 2;
    grid.Print();
    */

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(darkPurple);
        grid.Draw();
        block.Draw();
        block2.Draw();
        EndDrawing();
    }

    CloseWindow();
}