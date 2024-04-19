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
    private:
        // these values need not be known by other classes/files
        int numRows;
        int numCols;
        int cellSize;
        vector<Color> colors;
};

