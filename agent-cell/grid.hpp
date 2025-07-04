#pragma once
#include <vector>
#include "globals.hpp"

class Grid
{
public:
    Grid(int width, int height, int cellSize)
        : rows(height), cols(width), cellSize(cellSize), cells(rows, std::vector<int>(cols, 0)) {
        offsetLeft = 0;
        offsetTop = (WINDOW_HEIGHT- rows * cellSize) / 2;
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

private:
    int rows;
    int cols;
    int cellSize;
    int offsetLeft;
    int offsetTop;
    std::vector<std::vector<int>> cells;
};