#pragma once
#include "grid.hpp"

class Simulation
{
public:
  Simulation(int width, int height, int cellSize)
      : grid(width, height, cellSize), tempGrid(width, height, cellSize)
  {
    grid.FillRandomly();
  };
  void Draw();
  void Update();
  void SetCellValue(int row, int column, int value);
  int CountLiveNeighbors(int row, int column);

private:
  Grid grid;
  Grid tempGrid;
};