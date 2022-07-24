#include "GameOfLifeView.hpp"
#include <iostream>

GameOfLifeView::GameOfLifeView(const GameOfLifeModel &board)
    : board(board)
{
}

void GameOfLifeView::display() const
{
    for (int row = 0; row < board.getBoardHeight(); ++row)
    {
        for (int col = 0; col < board.getBoardWidth(); ++col)
        {
            if (board.isCellAlive(row, col))
                std::cout << "[*]";
            else
                std::cout << "[O]";
        }

        std::cout << std::endl;
    }
}
