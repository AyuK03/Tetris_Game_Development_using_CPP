#pragma once
#include "grid.h"
#include <vector>
#include "blocks.cpp"

class Game
{
public:
    Game();
    bool gameOver;
    int score;
    void Draw();
    void HandleInput();
    void MoveBlockDown();

private:
    Grid grid;
    vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Block GetRandomBlock();
    vector<Block> GetAllBlocks();
    bool isBlockOutside();
    void MoveBlockLeft();
    void MoveBlockRight();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int linesCleared, int moveDownPts);

};