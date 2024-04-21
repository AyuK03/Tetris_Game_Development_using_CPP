#pragma once     //to avoid a repeated file creation in the same project
#include <vector>
#include "raylib.h"

using namespace std;

class Grid{
    public:
        Grid();
        void Initialize();
        void Print();
        void Draw();
        int grid[20][10];
        bool isCellOutside(int r, int c);
        bool isCellEmpty(int row, int column);
        int ClearFullRows();
    private:
        // these values need not be known by other classes/files
        bool IsRowFull(int row);
        void ClearRow(int row);
        void ShiftRowDown(int row, int numRows);
        int numRows;
        int numCols;
        int cellSize;
        vector<Color> colors;
};

