#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid(){
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}

bool Grid::IsCellOutOfBounds(int row, int column)
{
    if(row >= 0 && row < numRows && column >= 0 && column < numCols)
    {
        return false;
    }
    return true;
}

bool Grid::IsCellAvailable(int row, int column)
{
    if(grid[row][column] == 0)
    {
        return true;
    }
    return false;
}

void Grid::Initialize()
{

    for (int row = 0; row < numRows; row++){
        for (int column = 0; column < numCols; column++)
        {
            grid[row][column] = 0;
        }
        
    }
}

void Grid::Print(){
    for (int row = 0; row < numRows; row++){
        for (int column = 0; column < numCols; column++)
        {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
}


void Grid::Draw(){

    
    for (int row = 0; row < numRows; row++){
        for (int column = 0; column < numCols; column++){

            int cellColorIndex = grid[row][column];
            DrawRectangle(column * cellSize+1, row * cellSize+1, cellSize-1, cellSize-1, colors[cellColorIndex]);
        }
    }
}

int Grid::ClearRows()
{
    int numRowsCleared = 0;
    for (int row = numRows-1; row >= 0; row--)
    {
        if (IsRowFull(row)){
            ClearRow(row);
            numRowsCleared++;
        }
        else if (numRowsCleared > 0)
        {
            MoveRowDown(row, numRowsCleared);
        }
    }
    return numRowsCleared;
}

bool Grid::IsRowFull(int row)
{
    for (int column = 0; column < numCols; column++)
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
    for (int column = 0; column < numCols; column++)
    {
        grid[row][column] = 0;
    }
}

void Grid::MoveRowDown(int row, int numRowsToMove)
{
    for (int column = 0; column < numCols; column++)
    {
        grid[row+numRowsToMove][column] = grid[row][column];
        grid[row][column] = 0;
    }
}
