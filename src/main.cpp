#include <raylib.h>
#include "gameFunctions.h"

double lastUpdate = 0;

bool WaitloopFinished(double waitTime)
{
    double currentUpdate = GetTime();
    if(currentUpdate - lastUpdate >= waitTime)
    {
        lastUpdate = currentUpdate;
        return true;
    }
    return false;
}

int main() 
{
    InitWindow(600, 600, "Tetris Game");
    SetTargetFPS(60);
    
    GameFunctions gameFunctions = GameFunctions();

    while(WindowShouldClose() == false){

        gameFunctions.InputHandler();
        if(WaitloopFinished(0.2))
        {
            gameFunctions.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(BLACK);
        gameFunctions.Draw();
        EndDrawing();
    }

    CloseWindow();
}