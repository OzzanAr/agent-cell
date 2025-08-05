#pragma once
#include <vector>
#include <memory>
#include "globals.hpp"
#include "gridElement.hpp"
#include "emptyCell.hpp"
#include "bunny.hpp"
#include "fox.hpp"
#include "food.hpp"

class Grid
{
public:
    Grid(int width, int height, int cellSize)
        : rows(height), cols(width), cellSize(cellSize) {
        SetupGridCells(height, width);
        CalculateOffsetValues();
    };

    void Draw();

    void SetupGridCells(int width, int height);
    void DeepCopyGrid(const Grid& copiedGrid);

    void SetCellValue(int row, int column, int value);
    int GetCellValue(int row, int column);
    bool IsWithinBounds(int row, int column);
    int GetRows() { return rows; }
    int GetColumns() { return cols; }
    void FillRandomly();
    void Clear();
    void ToggleCellValue(int row, int column, CellType cellType);
    int GetOffsetLeft() { return offsetLeft; }
    int GetOffsetTop() { return offsetTop; }
    int GetCellSize() { return cellSize; }
    void UpdateGridDimensons(int newWidth, int newHeight, int newCellSize);
    void CalculateOffsetValues();
    CellType GetCellTypeAt(int row, int column);
    
    // Getter and Setter for the Grid objects
    GridElement* GetAgentAt(int row, int column);
    void SetCell(int row, int column, std::unique_ptr<GridElement> element);
    void MoveElement(int fromRow, int fromColumn, int toRow, int toColumn);
    void RemoveElement(int row, int column);
    bool IsCellEmpty(int row, int column);

private:
    int rows;
    int cols;
    int cellSize;
    int offsetLeft;
    int offsetTop;
    std::vector<std::vector<std::unique_ptr<GridElement>>> cells;
};