#pragma once
#include <vector>

class Grid
{
public:
    Grid(int width, int height, int cellSize)
        : rows(height / cellSize), cols(width / cellSize), cellSize(cellSize), cells(rows, std::vector<int>(cols, 0)) {
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

private:
    int rows;
    int cols;
    int cellSize;
    std::vector<std::vector<int>> cells;
};