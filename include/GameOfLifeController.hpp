#pragma once
#include "GameOfLifeModel.hpp"
#include "GameOfLifeView.hpp"
#include "CommandSource.hpp"
// #include "UserCommands.hpp"

class GameOfLifeController
{
    GameOfLifeModel &board;
    const GameOfLifeView &view;

    void nextTour(std::vector<int> cellsOfFutureTour);

public:
    GameOfLifeController(GameOfLifeModel &board,
                        const GameOfLifeView &view);
                        
    // void play(); // Stage 1
    void chosenProcedure(CommandSource& commandSource);
};
