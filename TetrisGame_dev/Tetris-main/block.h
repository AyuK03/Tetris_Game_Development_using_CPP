#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

using namespace std;

class Block
{
    public:
        int id;
        Block();
        void Draw(int offsetX, int offsetY);
        void Move(int row, int column);
        vector<Position> GetCellPositions();
        void Rotate();
        void UndoRotation();
        map<int, vector<Position>> cells;

    private:
    int cellSize;
    int rotationState;
    vector<Color> colors;
    int rowOffset;
    int columnOffset;
};