#pragma once
#include "grid.hpp"

class Simulation
{
public:
    Simulation(int width, int height, int cellSize)
        : grid(width, height, cellSize), run(false) {
    };
    void Draw();
    void Update();
    void SetCellValue(int row, int column, int value);
    bool IsRunning() { return run; }
    void Start() { run = true; }
    void Stop() { run = false; }
    void ClearGrid();
    void CreateRandomState();
    void ToggleCell(int row, int column, CellType cellType);
    void CalculateMouseOffset(int& row, int& col);
    void UpdateGridSize(int newWidth, int newHeight, int newCellSize);
    int GetCurrentGeneration() { return currentGeneration; }
    void ResetGenerationCount() { currentGeneration = 0; }
    void RefreshActiveAgents();
    void PrintActiveAgents();
    
    void Tick();

private:
    Grid grid;
    bool run;
    int currentGeneration = 0;
    std::vector<GridElement*> activeAgents;
};