#include "cell.h"

Cell::Cell()
{
}
Cell::Cell(int cell1, int cell2)
{
    _cell1 = cell1;
    _cell2 = cell2;
}

void Cell::setCell1(int cell1)
{
    _cell1 = cell1;
}

void Cell::setCell2(int cell2)
{
    _cell2 = cell2;
}

int Cell::getCell1()
{
    return _cell1;
}
int Cell::getCell2()
{
    return _cell2;
}

Cell::~Cell()
{
}
