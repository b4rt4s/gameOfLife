#include "Cylinder.hpp"

int Cylinder::countAliveNeighbors(int row, int col) const
{
    int aliveCellsAround = 0;

    std::vector<int> vec_row = {row - 1, row, row + 1};
    std::vector<int> vec_col = {col - 1, col, col + 1};
                                        
    for (int i : vec_row)
    {
        for (int j : vec_col)
        {
            if(i < 0 || i >= getBoardHeight() || (i == row && j == col))
            {
                continue;
            }
            
            if(isCellAlive(i, (j + width) % width) == true)
            {
                ++aliveCellsAround;
            }
        }
    }

    return aliveCellsAround;
}