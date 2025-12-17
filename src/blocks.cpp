#include "block.h"
#include "position.h"

class LBlock : public Block
{
    public: 
        LBlock()
        {
            id = 1;
            //Different cells in that will be occupied depending on rotation. 1st number is Vertical, and 2nd is Horizontal
            //So (0, 2) is top right, and (2, 0) is bottom left of a 3x3 grid
            cells[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
            cells[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
            cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
            cells[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
        }
};

class JBlock : public Block
{
    public:
        JBlock()
        {
            id = 2;
            cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
            cells[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
            cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
            cells[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};
        }
};

class IBlock : public Block
{
    public:
        IBlock()
        {
            id = 3;
            cells[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
            cells[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
            cells[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
            cells[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
        }
};

class OBlock : public Block
{
    public:
        OBlock()
        {
            id = 4;
            //The same cells are filled whatever rotation it is in, so only one row needed here :)
            cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
        }
};

class SBlock : public Block
{
    public:
        SBlock()
        {
            id = 5;
            cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
            cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
            cells[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};
            cells[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
        }
};

class TBlock : public Block
{
    public:
        TBlock()
        {
            id = 6;
            cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
            cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
            cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
            cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
        }
};

class ZBlock : public Block
{
    public:
        ZBlock()
        {
            id = 7;
            cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
            cells[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
            cells[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
            cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
        }
};