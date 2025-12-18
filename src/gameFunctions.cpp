#include "gameFunctions.h"
#include <random>

GameFunctions::GameFunctions()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
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
    default:
        break;
    }
}

void GameFunctions::MoveBlockLeft()
{
    currentBlock.Move(0, -1);
    if(IsBlockOutOfBounds() || !BlockFits())
    {
        currentBlock.Move(0, 1);
    }
}

void GameFunctions::MoveBlockRight()
{
    currentBlock.Move(0, 1);
    if(IsBlockOutOfBounds() || !BlockFits())
    {
        currentBlock.Move(0, -1);
    }
}

void GameFunctions::MoveBlockDown()
{
    currentBlock.Move(1, 0);
    if(IsBlockOutOfBounds() || !BlockFits())
    {
        currentBlock.Move(-1, 0);
        LockBlock();
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
    currentBlock.Rotate();
    if(IsBlockOutOfBounds() || !BlockFits())
    {
        currentBlock.UndoRotation();
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
    nextBlock = GetRandomBlock();
}
