#pragma once
#include "grid.h"
#include "blocks.cpp"
class GameFunctions
{
    public:
        GameFunctions();
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        void Draw();
        void InputHandler();
        void HoldBlock(Block current);
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();
        Grid grid;
        bool gameOver;
        bool holdingBlockInitiated;
        int score;

    private:
        bool IsBlockOutOfBounds();
        bool BlockFits();
        bool hasHeldBlock;
        void RotateBlock();
        void LockBlock();
        void RestartGame();
        void UpdateScore(int linesCleared);
        void HoldBlock();
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        Block holdingBlock;
};