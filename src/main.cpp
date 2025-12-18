#include <raylib.h>
#include "gameFunctions.h"
#include <iostream>

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

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
    
    GameFunctions gameFunctions = GameFunctions();

    while(WindowShouldClose() == false){

        gameFunctions.InputHandler();
        if(WaitloopFinished(0.2))
        {
            gameFunctions.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTextEx(font, "Score", {405, 15}, 38, 2, WHITE);

        char scoreText[10];
        sprintf(scoreText, "%d", gameFunctions.score);

        DrawTextEx(font, scoreText, {405, 50}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {415, 150}, 38, 2, WHITE);
        if(gameFunctions.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {360, 450}, 38, 2, WHITE);
            DrawTextEx(font, "PRESS 'ENTER' TO RESTART", {340, 500}, 14, 2, WHITE);
        }
        gameFunctions.Draw();
        EndDrawing();
    }

    CloseWindow();
}