#pragma once
#include <vector>

struct Cell
{
  bool isAlive;
};

enum class GameMode
{
  DEBUG,
  NORMAL
};

class GameOfLifeModel
{
protected:
  const int width;
  const int height;

  std::vector<Cell> board;

  const GameMode mode;

  Cell &getCellAt(int row, int col);
  const Cell &getCellAt(int row, int col) const;
  bool isCellOnTheBoard(int row, int col) const;

public:
  GameOfLifeModel();

  // void debugDisplay() const; // Stage 1

  int getBoardWidth() const;
  int getBoardHeight() const;
  bool isCellAlive(int row, int col) const;
  int futureStateOfCell(int row, int col) const;
  std::vector<int> futureTour() const;
  void updateStateOfCell(int row, int col, bool state);

  virtual int countAliveNeighbors(int row, int col) const;
};
