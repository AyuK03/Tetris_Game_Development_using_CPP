#pragma once
#include "grid.h"
#include <vector>
#include "blocks.cpp"

class Game
{
public:
    Game();
    Grid grid;
    Block GetRandomBlock();
    vector<Block> GetAllBlocks();
    void Draw();
    void HandleInput();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();

private:
    vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;

};