#pragma once
#include "GameOfLifeModel.hpp"

class GameOfLifeView
{
    const GameOfLifeModel &board;

public:
    GameOfLifeView(const GameOfLifeModel &board);

    void display() const;
};
