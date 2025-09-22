#include "grid.hpp"
#include "globals.hpp"
#include <raylib.h>
#include <iostream>

void Grid::Draw(std::vector<GridElement*> activeAgents)
{

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            Color cellColor = CUSTOM_GREY;

            if (!activeAgents.empty()) {
                for (auto agent : activeAgents) {
                    if (agent->GetCoordinates().first == row && agent->GetCoordinates().second == col) {
						cellColor = agent->GetColor();
                    }
                }
            }

            // Minus one on the width and height of the CellSize when drawing the rectangles to display grid lines.
            DrawRectangle(col * cellSize + offsetLeft, row * cellSize + offsetTop, cellSize - 1, cellSize - 1, cellColor);
        }
    }
}

void Grid::SetCellValue(int row, int column, int value)
{
    if (IsWithinBounds(row, column))
    {
        cells[row][column]->SetValue(value);
    }
}

int Grid::GetCellValue(int row, int column)
{
    if (IsWithinBounds(row, column))
    {
        return cells[row][column]->GetValue();
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
            cells[row][col]->SetValue((randValue == 4) ? 1 : 0);
        }
    }
}

void Grid::Clear()
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            cells[row][col]->SetValue(0);
        }
    }
}

void Grid::ToggleCellValue(int row, int column, CellType cellType)
{
    if (IsWithinBounds(row, column))
    {
        switch (cellType) {
            case EMPTYCELL:
				cells[row][column] = std::make_unique<EmptyCell>();
                break;
            case BUNNY:
				cells[row][column] = std::make_unique<Bunny>(row, column);
                break;
            case FOX:
				cells[row][column] = std::make_unique<Fox>(row, column);
                break;
            case GRASS:
				cells[row][column] = std::make_unique<Grass>(row, column);
                break;
        }
    }
}

void Grid::CalculateOffsetValues()
{
	this->offsetLeft = (WINDOW_WIDTH - cols * cellSize) / 2;
	this->offsetTop = (WINDOW_HEIGHT- rows * cellSize) / 2;
}

CellType Grid::GetCellTypeAt(int row, int column)
{
    if (IsWithinBounds(row, column)) {
        return cells[row][column]->GetType();
    }
}

GridElement* Grid::GetAgentAt(int row, int column)
{
    if (IsWithinBounds(row, column)) {
		return cells[row][column].get();
    }
}

void Grid::SetCell(int row, int column, std::unique_ptr<GridElement> element)
{
    cells[row][column] = std::move(element);
}

void Grid::MoveElement(int fromRow, int fromColumn, int toRow, int toColumn)
{
    if (!IsCellEmpty(toRow, toColumn)) return;

	cells[toRow][toColumn] = std::move(cells[fromRow][fromColumn]);
	cells[fromRow][fromColumn] = std::make_unique<EmptyCell>();
}

void Grid::RemoveElement(int row, int column)
{
    if (IsWithinBounds(row, column)) {
        cells[row][column] = std::make_unique<EmptyCell>();
    }
}

bool Grid::IsCellEmpty(int row, int column)
{
    if (IsWithinBounds(row, column)) {
        if (cells[row][column]->GetType() == CellType::EMPTYCELL)
            return true;
    }

    return false;
}

std::optional<std::pair<int, int>> Grid::FindEmptyNeighbour(std::pair<int, int> coordinates)
{
    int currentRow, currentColumn;

    for (const auto& offset : neighborOffsets) {
		currentRow = coordinates.first + offset.first;
		currentColumn = coordinates.second + offset.second;

        if (IsCellEmpty(currentRow, currentColumn)) {
            return std::pair<int, int>(currentRow, currentColumn);
        }
    }
}

void Grid::SetupGridCells(int cellRows, int cellCols)
{
    cells.resize(cellRows);
    for (auto& cellRow : cells) {
        cellRow.resize(cellCols);
        for (auto& cell : cellRow) {
            cell = std::make_unique<EmptyCell>();
        }
    }
}

void Grid::DeepCopyGrid(const Grid& copiedGrid)
{
    int rows = copiedGrid.cells.size(); 
    int cols = copiedGrid.cells[0].size();

    cells.resize(rows);
    for (int i = 0; i < rows; ++i) {
        cells[i].resize(cols);
        for (int j = 0; j < cols; ++j) {
            if (copiedGrid.cells[i][j]) {
                cells[i][j] = copiedGrid.cells[i][j]->clone();
            }
            else {
                cells[i][j] = nullptr;
            }
        }
    }
}

void Grid::UpdateGridDimensons(int newWidth, int newHeight, int newCellSize)
{
    this->rows = newHeight;
    this->cols = newWidth;
    this->cellSize = newCellSize;
    SetupGridCells(newHeight, newWidth);
    CalculateOffsetValues();
}

