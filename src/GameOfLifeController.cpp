#include "GameOfLifeController.hpp"
#include <iostream>
#include <unistd.h>

namespace {
    constexpr bool alive = true;
    constexpr bool dead = false;
}

GameOfLifeController::GameOfLifeController(GameOfLifeModel &board,
                                            const GameOfLifeView &view)
    :   board(board),
    view(view)
{
}

void GameOfLifeController::nextTour(std::vector<int> cellsOfFutureTour)
{
    for (int row = 0; row < board.getBoardHeight(); ++row)
    {
        for (int col = 0; col < board.getBoardWidth(); ++col)
        {
            if (cellsOfFutureTour.at(row * board.getBoardWidth() + col) == 1)
            {
                board.updateStateOfCell(row, col, alive);
                
                continue;
            }

            board.updateStateOfCell(row, col, dead);
        }
    }
}

void GameOfLifeController::chosenProcedure(CommandSource& commandSource)
{
    while (true)
    {
        view.display();

        std::string command = commandSource.nextCommand();

        // UserCommands test;

        if (command == "quit")
        {
            system("clear");
            return;
        }

        if (command == "next")
        {   
            system("clear");

            nextTour(board.futureTour());

            continue;
        }

        // if (command == "toggle")
        // {
        //     int row = test.getRow() , col = test.getCol();

        //     if(board.isCellAlive(row, col))
        //     {
        //         board.updateStateOfCell(row, col, dead);
        //     }
        //     else
        //     {
        //         board.updateStateOfCell(row, col, alive);
        //     }
        // }
    }
}

