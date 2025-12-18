#include "gameFunctions.h"
#include <random>

GameFunctions::GameFunctions()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
    score = 0;
}

Block GameFunctions::GetRandomBlock()
{
    if(blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> GameFunctions::GetAllBlocks()
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void GameFunctions::Draw()
{
    grid.Draw();
    currentBlock.Draw();
}

void GameFunctions::InputHandler()
{
    int keyPressed = GetKeyPressed();

    if(gameOver)
    {
        //Show Game Over Screen
        if(keyPressed == KEY_ENTER)
        {
            gameOver = false;
            RestartGame();
        }
    }

    switch (keyPressed)
    {
    case KEY_LEFT:
        MoveBlockLeft();
        break;
    case KEY_RIGHT:
        MoveBlockRight();
        break;
    case KEY_DOWN:
        MoveBlockDown();
        break;
    case KEY_UP:
        RotateBlock();
        break;
    case KEY_ENTER:
        RestartGame();
        break;
    }    
}

void GameFunctions::MoveBlockLeft()
{
    if(!gameOver)
    {
        currentBlock.Move(0, -1);
        if(IsBlockOutOfBounds() || !BlockFits())
        {
            currentBlock.Move(0, 1);
        }
    }
    
}

void GameFunctions::MoveBlockRight()
{
    if(!gameOver)
    {
        currentBlock.Move(0, 1);
        if(IsBlockOutOfBounds() || !BlockFits())
        {
            currentBlock.Move(0, -1);
        }
    }   
}

void GameFunctions::MoveBlockDown()
{
    if(!gameOver)
    {
        currentBlock.Move(1, 0);
        if(IsBlockOutOfBounds() || !BlockFits())
        {
            currentBlock.Move(-1, 0);
            LockBlock();
        }
    }
}

bool GameFunctions::IsBlockOutOfBounds()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item:tiles)
    {
        if(grid.IsCellOutOfBounds(item.row, item.column))
        {
            return true;
        }       
    }
    return false;
}

bool GameFunctions::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item:tiles)
    {
        if(!grid.IsCellAvailable(item.row, item.column))
        {
            return false;
        }
    }
    return true;
    
}

void GameFunctions::RotateBlock()
{
    if(!gameOver)
    {
        currentBlock.Rotate();
        if(IsBlockOutOfBounds() || !BlockFits())
        {
            currentBlock.UndoRotation();
        }
    }
}

void GameFunctions::LockBlock()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item:tiles)
    {
        grid.grid[item.row][item.column] = currentBlock.id;
    }
    currentBlock = nextBlock;
    if (!BlockFits())
    {
        gameOver = true;
    }
    nextBlock = GetRandomBlock();
    int rowsCleared = grid.ClearRows();
    UpdateScore(rowsCleared);
}

void GameFunctions::RestartGame()
{
    grid.Initialize();
    score = 0;
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}

void GameFunctions::UpdateScore(int linesCleared)
{
    switch(linesCleared)
    {
    case 1:
        score += 100;
        break;
    case 2:
        score += 250;
        break;
    case 3: 
        score += 500;
        break;
    case 4:
        score += 1000;
        break;
    default:
        break;
    }
}
