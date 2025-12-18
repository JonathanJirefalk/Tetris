#pragma once
#include <raylib.h>
#include <vector>
class Grid
{
    
    public:
        Grid();
        
        int grid[20][10];
        
        bool IsCellOutOfBounds(int row, int column);
        bool IsCellAvailable(int row, int column);
        void Initialize();
        void Print();
        void Draw();
        int ClearRows();
        
        

    private:
        int numRows;
        int numCols;
        int cellSize;
        bool IsRowFull(int row);
        void ClearRow(int row);
        void MoveRowDown(int row, int numRowsToMove);
        std::vector<Color> colors;

};