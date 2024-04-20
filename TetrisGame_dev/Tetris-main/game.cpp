#include "game.h"
#include <random>

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}

Block Game::GetRandomBlock()
{
    if(blocks.empty()){
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block blk = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return blk;
}

vector<Block> Game::GetAllBlocks()
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();

}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();
    switch (keyPressed)
    {
    case KEY_LEFT:
        MoveBlockLeft();
        break;
    case KEY_RIGHT:
        MoveBlockRight();
        break;
    case KEY_DOWN:
        MoveBlockDown();
        break;
    default:
        break;
    }

}

void Game::MoveBlockLeft()
{
    currentBlock.Move(0,-1);

}

void Game::MoveBlockRight()
{
    currentBlock.Move(0,1);

}

void Game::MoveBlockDown()
{
    currentBlock.Move(1,0);

}



