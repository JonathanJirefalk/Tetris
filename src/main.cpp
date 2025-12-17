#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"

int main() 
{
    InitWindow(300, 600, "Tetris Game");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.Print();

    TBlock block = TBlock();
    
    while(WindowShouldClose() == false){

        BeginDrawing();
        ClearBackground(BLACK);
        grid.Draw();
        block.Draw();
        EndDrawing();
    }

    CloseWindow();
}