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
        Grid grid;

    private:
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
};