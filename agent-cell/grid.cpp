#include "grid.hpp"
#include "globals.hpp"
#include <raylib.h>

void Grid::Draw()
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            Color cellColor = cells[row][col].GetValue() == 1 ? CUSTOM_GREEN : CUSTOM_GREY;

            // Minus one on the width and height of the CellSize when drawing the rectangles to display grid lines.
            DrawRectangle(col * cellSize + offsetLeft, row * cellSize + offsetTop, cellSize - 1, cellSize - 1, cellColor);
        }
    }
}

void Grid::SetCellValue(int row, int column, int value)
{
    if (IsWithinBounds(row, column))
    {
        cells[row][column].SetValue(value);
    }
}

int Grid::GetCellValue(int row, int column)
{
    if (IsWithinBounds(row, column))
    {
        return cells[row][column].GetValue();
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

void Grid::FillRandomly()
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            int randValue = GetRandomValue(0, 4);
            cells[row][col].SetValue((randValue == 4) ? 1 : 0);
        }
    }
}

void Grid::Clear()
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            cells[row][col].SetValue(0);
        }
    }
}

//void Grid::ToggleCellValue(int row, int column)
//{
//    if (IsWithinBounds(row, column))
//    {
//        cells[row][column] = !cells[row][column];
//    }
//}

void Grid::CalculateOffsetValues()
{
	this->offsetLeft = (WINDOW_WIDTH - cols * cellSize) / 2;
	this->offsetTop = (WINDOW_HEIGHT- rows * cellSize) / 2;
}

void Grid::UpdateGridDimensons(int newWidth, int newHeight, int newCellSize)
{
    this->rows = newHeight;
    this->cols = newWidth;
    this->cellSize = newCellSize;
    this->cells.resize(newHeight);
    for (auto& row : cells) {
        row.resize(newWidth); // properly sizes every row
    }
    CalculateOffsetValues();
}

