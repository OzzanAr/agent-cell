#include "simulation.hpp"
#include "globals.h"
#include <raylib.h>
#include <vector>
#include <utility>

void Simulation::Draw()
{
  grid.Draw();
}

void Simulation::SetCellValue(int row, int column, int value)
{
  grid.SetCellValue(row, column, value);
}

void Simulation::CountLiveNeighbors(int row, int column)
{
  int liveNeighbors = 0;
  std::vector<std::pair<int, int>> neighborOffsets = {
      {-1, 0},  // Above
      {1, 0},   // Below
      {0, -1},  // Left
      {0, 1},   // Right
      {-1, -1}, // Upper left
      {-1, 1},  // Upper right
      {1, -1},  // Lower Left
      {1, 1},   // Lower right
  };

  for (const auto &offset : neighborOffsets)
  {
    int neighborRow = row + offset.first;
    int neighborColumn = column + offset.second;
    liveNeighbors += grid.GetCellValue(neighborRow, neighborColumn);
  }
}
