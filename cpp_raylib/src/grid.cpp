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
  if (IsWithinBounds(row, column))
  {
    cells[row][column] = value;
  }
}

int Grid::GetCellValue(int row, int column)
{
  if (IsWithinBounds(row, column))
  {
    return cells[row][column];
  }
  return 0;
}

bool Grid::IsWithinBounds(int row, int column)
{

  if (row >= 0 && row < rows && column >= 0 && column < cols)
  {
    return true;
  }
  return false;
}
