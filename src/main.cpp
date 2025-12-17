#include <raylib.h>
#include "grid.h"

int main() 
{
    InitWindow(300, 600, "Tetris Game");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.grid[0][0] = 1;
    grid.grid[3][5] = 4;
    grid.grid[17][8] = 7;
    grid.Print();
    
    while(WindowShouldClose() == false){

        BeginDrawing();
        ClearBackground(BLACK);
        grid.Draw();
        EndDrawing();
    }

    CloseWindow();
}