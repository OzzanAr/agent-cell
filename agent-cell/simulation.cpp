#include "simulation.hpp"
#include "globals.hpp"
#include <raylib.h>
#include <vector>
#include <utility>
#include <iostream>
#include "utils.hpp"

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::Update()
{
    RefreshActiveAgents();
    PrintActiveAgents();

    if (IsRunning())
    {
        Tick();
        currentGeneration++;
    }
}

void Simulation::SetCellValue(int row, int column, int value) {
    grid.SetCellValue(row, column, value);
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

void Simulation::ToggleCell(int row, int column, CellType cellType)
{
    if (!IsRunning())
    {
        grid.ToggleCellValue(row, column, cellType);
    }
}

void Simulation::CalculateMouseOffset(int& row, int& col)
{
	Vector2 mousePos = GetMousePosition();
    col = (mousePos.x - grid.GetOffsetLeft()) / grid.GetCellSize();
	row = (mousePos.y - grid.GetOffsetTop()) / grid.GetCellSize();
}

void Simulation::UpdateGridSize(int newWidth, int newHeight, int newCellSize)
{
    grid.UpdateGridDimensons(newWidth, newHeight, newCellSize);
    ResetGenerationCount();
}

void Simulation::RefreshActiveAgents()
{
    activeAgents.clear();

	for (int row = 0; row < grid.GetRows(); row++)
	{
		for (int column = 0; column < grid.GetColumns(); column++)
		{
			if (grid.GetCellTypeAt(row, column) != CellType::EMPTYCELL) {
				GridElement* element = grid.GetAgentAt(row, column);
				if (element) {
					activeAgents.push_back(element);
				}
			}
		}
	}
}

void Simulation::PrintActiveAgents() {
    if (IsRunning() && !activeAgents.empty()) {
        std::cout << "=== Active Agents (" << activeAgents.size() << ") ===" << std::endl;
        for (size_t i = 0; i < activeAgents.size(); ++i) {
            std::cout << "Agent " << i << ": " << utils::EnumToString(activeAgents[i]->GetType()) << std::endl;
            std::cout << "Coordinate: " << activeAgents[i]->GetCoordinates().first << " " << activeAgents[i]->GetCoordinates().second<< std::endl;
        }
        std::cout << "[END] PRINTING DONE" << std::endl;
    }
}

void Simulation::Tick()
{
    if (activeAgents.empty()) {
        this->run = false;
        return;
    }

    for (auto& agent : activeAgents) {
        agent->prepare(grid);
    }

    for (auto& agent : activeAgents) {
        agent->execute(grid);
    }
}
