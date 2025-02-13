#include "grid.hpp"
#include <raylib.h>
#include "globals.h"

void Grid::Draw()
{
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      Color color = cells[row][col] == 1 ? CUSTOM_GREEN : CUSTOM_GREY;
    }
  }
}