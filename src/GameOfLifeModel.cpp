#include "GameOfLifeModel.hpp"
// #include <iostream> // Stage 1

GameOfLifeModel::GameOfLifeModel()
    : width(10),
    height(10),
    board(width * height, {false}),
    mode(GameMode::DEBUG)
{
    if (mode == GameMode::NORMAL)
    {
        getCellAt(0, 1).isAlive = true;
        getCellAt(1, 2).isAlive = true;
        getCellAt(2, 0).isAlive = true;
        getCellAt(2, 1).isAlive = true;
        getCellAt(2, 2).isAlive = true;
    }
    else if(mode == GameMode::DEBUG)
    {
        // block
        getCellAt(0, 0).isAlive = true;
        getCellAt(0, 1).isAlive = true;
        getCellAt(1, 0).isAlive = true;
        getCellAt(1, 1).isAlive = true;

        // tub
        getCellAt(2, 4).isAlive = true;
        getCellAt(3, 3).isAlive = true;
        getCellAt(4, 4).isAlive = true;
        getCellAt(3, 5).isAlive = true;

        // blinker
        getCellAt(6, 7).isAlive = true;
        getCellAt(6, 8).isAlive = true;
        getCellAt(6, 9).isAlive = true;

        // beacon
        getCellAt(6, 0).isAlive = true;
        getCellAt(6, 1).isAlive = true;
        getCellAt(7, 0).isAlive = true;
        getCellAt(9, 2).isAlive = true;
        getCellAt(9, 3).isAlive = true;
        getCellAt(8, 3).isAlive = true;
    }
}

Cell &GameOfLifeModel::getCellAt(int row, int col)
{
    return board.at(row * width + col);
}

const Cell &GameOfLifeModel::getCellAt(int row, int col) const
{
    return board.at(row * width + col);
}

// Stage 1

// void GameOfLifeModel::debugDisplay() const
// {
//     for (int row = 0; row < height; ++row)
//     {
//         for (int col = 0; col < width; ++col)
//         {
//             std::cout << "[" <<  getCellAt(row, col).isAlive << "]";
//         }

//         std::cout << std::endl;
//     }
// }

int GameOfLifeModel::getBoardWidth() const
{
    return width;
}

int GameOfLifeModel::getBoardHeight() const
{
    return height;
}

bool GameOfLifeModel::isCellOnTheBoard(int row, int col) const
{
    return (row >= 0 && row < getBoardHeight()) 
            && (col >= 0 && col < getBoardWidth());
}

bool GameOfLifeModel::isCellAlive(int row, int col) const
{
    return isCellOnTheBoard(row, col) && getCellAt(row, col).isAlive;
}

int GameOfLifeModel::countAliveNeighbors(int row, int col) const
{
    int aliveCellsAround = 0;

    std::vector<int> vec_row = {row - 1, row, row + 1};
    std::vector<int> vec_col = {col - 1, col, col + 1};

    for (int i : vec_row)
    {
        for (int j : vec_col)
        {
            if(isCellAlive(i, j) && !(i == row && j == col))
            {
                ++aliveCellsAround;
            }
        }
    }

    return aliveCellsAround;
}

int GameOfLifeModel::futureStateOfCell(int row, int col) const
{
    if (!(isCellOnTheBoard(row, col)))
    {
        return -1;
    }

    if((!(isCellAlive(row, col))
    && countAliveNeighbors(row, col) == 3) ||
    (isCellAlive(row, col) &&
    (countAliveNeighbors(row, col) == 2 ||
    countAliveNeighbors(row, col) == 3)))
    {
        return 1;
    }
    
    return 0;
}

std::vector<int> GameOfLifeModel::futureTour() const
{
    std::vector<int> cellsOfFutureTour;

    for (int row = 0; row < getBoardHeight(); ++row)
    {
        for (int col = 0; col < getBoardWidth(); ++col)
        {
            cellsOfFutureTour.push_back(futureStateOfCell(row, col));
        }
    }

    return cellsOfFutureTour;
}

void GameOfLifeModel::updateStateOfCell(int row, int col, bool state)
{
    if (!(isCellOnTheBoard(row, col)))
    {
        return;
    }

    getCellAt(row, col).isAlive = state;
}
