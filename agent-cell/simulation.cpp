#include "simulation.hpp"
#include "globals.hpp"
#include <raylib.h>
#include <vector>
#include <utility>

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::Update()
{
    if (IsRunning())
    {
        for (int row = 0; row < grid.GetRows(); row++)
        {
            for (int column = 0; column < grid.GetColumns(); column++)
            {
                int liveNeighbors = CountLiveNeighbors(row, column);
                int cellValue = grid.GetCellValue(row, column);

                if (cellValue == 1)
                {
                    if (liveNeighbors > 3 || liveNeighbors < 2)
                    {
                        tempGrid.SetCellValue(row, column, 0);
                    }
                    else
                    {
                        tempGrid.SetCellValue(row, column, 1);
                    }
                }
                else
                {
                    if (liveNeighbors == 3)
                    {
                        tempGrid.SetCellValue(row, column, 1);
                    }
                    else
                    {
                        tempGrid.SetCellValue(row, column, 0);
                    }
                }
            }
        }
        grid.DeepCopyGrid(tempGrid);
        currentGeneration++;
    }
}

void Simulation::SetCellValue(int row, int column, int value) {
    grid.SetCellValue(row, column, value);
}

int Simulation::CountLiveNeighbors(int row, int column)
{
    int liveNeighbors = 0;
    std::vector<std::pair<int, int>> neighborOffsets = {
        {-1, 0},  // Above
        {1, 0},   // Below
        {0, -1},  // Left
        {0, 1},   // Right
        {-1, -1}, // Upper left
        {-1, 1},  // Upper right
        {1, -1},  // Lower Left
        {1, 1},   // Lower right
    };

    for (const auto& offset : neighborOffsets)
    {
        int neighborRow = (row + offset.first + grid.GetRows()) % grid.GetRows();
        int neighborColumn = (column + offset.second + grid.GetColumns()) % grid.GetColumns();
        liveNeighbors += grid.GetCellValue(neighborRow, neighborColumn);
    }

    return liveNeighbors;
}

void Simulation::ClearGrid()
{
    if (!IsRunning())
    {
        grid.Clear();
    }
}

void Simulation::CreateRandomState()
{
    if (!IsRunning())
    {
        grid.FillRandomly();
    }
}

//void Simulation::ToggleCell(int row, int column)
//{
//    if (!IsRunning())
//    {
//        grid.ToggleCellValue(row, column);
//    }
//}

void Simulation::CalculateMouseOffset(int& row, int& col)
{
	Vector2 mousePos = GetMousePosition();
    col = (mousePos.x - grid.GetOffsetLeft()) / grid.GetCellSize();
	row = (mousePos.y - grid.GetOffsetTop()) / grid.GetCellSize();
}

void Simulation::UpdateGridSize(int newWidth, int newHeight, int newCellSize)
{
    grid.UpdateGridDimensons(newWidth, newHeight, newCellSize);
    tempGrid.UpdateGridDimensons(newWidth, newHeight, newCellSize);
    ResetGenerationCount();
}
