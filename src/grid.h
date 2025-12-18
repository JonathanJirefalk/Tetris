#pragma once
#include <raylib.h>
#include <vector>
class Grid
{
    
    public:
        Grid();
        
        int grid[20][10];
        
        bool IsCellOutOfBounds(int row, int column);
        void Initialize();
        void Print();
        void Draw();
        

    private:
        int numRows;
        int numCols;
        int cellSize;

        std::vector<Color> colors;

};