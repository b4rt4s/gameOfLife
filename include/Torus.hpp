#pragma once
#include "GameOfLifeModel.hpp"

class Torus : public GameOfLifeModel {
public:
    int countAliveNeighbors(int row, int col) const override;
};