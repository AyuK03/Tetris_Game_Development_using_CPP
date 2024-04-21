#include "grid.h"
#include<iostream>
#include "colors.h"
using namespace std;

Grid::Grid(){
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize(){    //Initializing all cell values to zero
    for(int row = 0; row < numRows; row++){
        for(int column = 0; column < numCols; column++){
            grid[row][column] = 0;
        }
    }
}

void Grid::Print(){         // to see the state of the grid at an instance
    for(int row=0; row < numRows; row++){
        for(int col=0; col < numCols; col++){
            cout << grid[row][col] << " " << std::flush;
        }
        cout << endl;
    }
}

void Grid::Draw(){
    for(int row = 0; row < numRows; row++){
        for(int col = 0; col < numCols; col++){
            int cellValue = grid[row][col];     // extracting cell's color value
            DrawRectangle(col*cellSize+1, row*cellSize+1, cellSize-2, cellSize-2, colors[cellValue]); // col*cellSize+1, row*cellSize+1 gives top left corner of each box
            // we +1 and -1 in prev line to make the cells separate from each other so that the color behind them, i.e the background be visible to notice each cell
        }
    }
}

bool Grid::isCellOutside(int r, int c)
{
    if(r >= 0 && r < numRows && c >= 0 && c < numCols)
    {
        return false;
    }
    return true;
}

bool Grid::isCellEmpty(int row, int column)
{
    if(grid[row][column]==0)
    {
        return true;
    }
    return false;
}

int Grid::ClearFullRows()
{
    int completedRows = 0;
    for(int row = numRows-1; row >=0; row--)
    {
        if(IsRowFull(row))
        {
            ClearRow(row);
            completedRows++;
        }
        else if(completedRows > 0)
        {
            ShiftRowDown(row, completedRows);
        }
    }
    return completedRows;
}

bool Grid::IsRowFull(int row)
{
    for(int column = 0; column < numCols; column++)
    {
        if(grid[row][column] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for(int column = 0; column < numCols; column++)
    {
        grid[row][column] = 0;
    }

}

void Grid::ShiftRowDown(int row, int numRows)
{
    for(int col = 0; col < numCols; col++)
    {
        grid[row + numRows][col] = grid[row][col];  // copy values of row above and replace it for the row below
        grid[row][col] = 0;
    }
}
