#include "grid.hpp"
#include "globals.h"
#include <raylib.h>

void Grid::Draw()
{
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      Color cellColor = cells[row][col] == 1 ? CUSTOM_GREEN : CUSTOM_GREY;
      DrawRectangle(col * cellSize, row * cellSize, cellSize - 1, cellSize - 1, cellColor);
    }
  }
}

void Grid::SetCellValue(int row, int column, int value)
{
  if (row >= 0 && row < rows && column >= 0 && column < cols)
  {
    cells[row][column] = value;
  }
}
