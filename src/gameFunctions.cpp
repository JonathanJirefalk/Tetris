#include "gameFunctions.h"
#include <random>

GameFunctions::GameFunctions()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
    holdingBlockInitiated = false;
    hasHeldBlock = false;
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
    return {LBlock(), JBlock(), IBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void GameFunctions::Draw()
{
    grid.Draw();
    currentBlock.Draw(1, 1);

    if(nextBlock.id == 3 || nextBlock.id == 4)
    {
        nextBlock.Draw(300, 250);
    }
    else
    {
        nextBlock.Draw(320, 250);
    }

    if(!gameOver && holdingBlockInitiated)
    {
        if(holdingBlock.id == 3 || holdingBlock.id == 4)
        {
            holdingBlock.Draw(300, 420);
        }
        else
        {
            holdingBlock.Draw(320, 420);
        }
        
    }
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
    case KEY_SPACE:
        if(!hasHeldBlock && !gameOver)
        {
            HoldBlock(GetAllBlocks()[currentBlock.id-1]);
            hasHeldBlock = true;
        }
        break;
    }    
}
void GameFunctions::HoldBlock(Block current)
{
    if(!holdingBlockInitiated)
    {
        holdingBlock = current;
        currentBlock = nextBlock;
        nextBlock = GetRandomBlock();
        holdingBlockInitiated = true;
    }
    else
    {
        currentBlock = holdingBlock;
        holdingBlock = current;
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
    hasHeldBlock = false;
}

void GameFunctions::RestartGame()
{
    grid.Initialize();
    score = 0;
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    hasHeldBlock = false;
    holdingBlockInitiated = false;
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
