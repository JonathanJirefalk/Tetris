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
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();
        Grid grid;

    private:
        bool IsBlockOutOfBounds();
        bool BlockFits();
        void RotateBlock();
        void LockBlock();
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
};