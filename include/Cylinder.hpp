#pragma once
#include "GameOfLifeModel.hpp"

class Cylinder : public GameOfLifeModel {
public:
    int countAliveNeighbors(int row, int col) const override;
};