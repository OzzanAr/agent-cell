#pragma once
#include <vector>

class Grid
{
public:
  Grid(int width, int height, int cellSize)
      : rows(height / cellSize), cols(width / cellSize), cell_size(cellSize), cells(rows, std::vector<int>(cols, 0)) {};
  void Draw();

private:
  int rows;
  int cols;
  int cell_size;
  std::vector<std::vector<int>> cells;
};