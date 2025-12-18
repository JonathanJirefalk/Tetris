#include <raylib.h>
#include "gameFunctions.h"

int main() 
{
    InitWindow(300, 600, "Tetris Game");
    SetTargetFPS(60);
    
    GameFunctions gameFunctions = GameFunctions();

    while(WindowShouldClose() == false){

        gameFunctions.InputHandler();
        BeginDrawing();
        ClearBackground(BLACK);
        gameFunctions.Draw();
        EndDrawing();
    }

    CloseWindow();
}