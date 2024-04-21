#include "block.h"
#include "raylib.h"
using namespace std;

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    rowOffset = 0;
    columnOffset = 0;
    colors = GetCellColors();
}

void Block::Draw()
{
    vector<Position> tiles = GetCellPositions();;
    for(Position item: tiles){
        DrawRectangle(item.column * cellSize + 11, item.row * cellSize + 11, cellSize-1, cellSize-1, colors[id]);
    }
}

void Block::Move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
}

// We are making a separate method to find the new location of the block rather than
// doing it in the Move blk itself so that this can be later also used when dealing with collisions - Abstraction

vector<Position> Block::GetCellPositions()
{
    vector<Position> tiles = cells[rotationState];
    vector<Position> movedTiles;
    for(Position item: tiles)
    {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;

}

void Block::Rotate()
{
    rotationState++;
    if(rotationState==(int)cells.size())
    {
        rotationState = 0;
    };
}

void Block::UndoRotation()
{
    rotationState--;
    if(rotationState==-1)
    {
        rotationState = cells.size()-1;
    }
}
