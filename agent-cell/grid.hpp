#pragma once
#include <vector>
#include "globals.hpp"

class Grid
{
public:
    Grid(int width, int height, int cellSize)
        : rows(height), cols(width), cellSize(cellSize), cells(rows, std::vector<int>(cols, 0)) {
        CalculateOffsetValues();
    };
    void Draw();
    void SetCellValue(int row, int column, int value);
    int GetCellValue(int row, int column);
    bool IsWithinBounds(int row, int column);
    int GetRows() { return rows; }
    int GetColumns() { return cols; }
    void FillRandomly();
    void Clear();
    void ToggleCellValue(int row, int column);
    int GetOffsetLeft() { return offsetLeft; }
    int GetOffsetTop() { return offsetTop; }
    int GetCellSize() { return cellSize; }
    void UpdateGridDimensons(int newWidth, int newHeight, int newCellSize);
    void CalculateOffsetValues();

private:
    int rows;
    int cols;
    int cellSize;
    int offsetLeft;
    int offsetTop;
    std::vector<std::vector<int>> cells;
};