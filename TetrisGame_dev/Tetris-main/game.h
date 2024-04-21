#pragma once
#include "grid.h"
#include <vector>
#include "blocks.cpp"

class Game
{
public:
    Game();
    ~Game();
    bool gameOver;
    int score;
    void Draw();
    void HandleInput();
    void MoveBlockDown();
    Music music;
    Sound gameOver_sound;

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
    Sound rotateSound;
    Sound clearSound;

};