#include "Torus.hpp"

int Torus::countAliveNeighbors(int row, int col) const
{
    int aliveCellsAround = 0;

    std::vector<int> vec_row = {row - 1, row, row + 1};
    std::vector<int> vec_col = {col - 1, col, col + 1};

    for (int i : vec_row)
    {
        for (int j : vec_col)
        {
            if(i == row && j == col)
            {
                continue;
            }
            if(isCellAlive((i + height) % height, (j + width) % width) == true)
            {
                ++aliveCellsAround;
            }
        }
    }

    return aliveCellsAround;
}