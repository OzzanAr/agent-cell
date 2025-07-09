#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <raymath.h>
#include "globals.hpp"
#include "simulation.hpp"
#include <algorithm>
#include <string>

void CalculateCellSize(int &cellSize, int gridCols, int gridRows) {
    cellSize = WINDOW_WIDTH + WINDOW_HEIGHT;

    if (cellSize * gridCols > WINDOW_WIDTH) {
        cellSize = WINDOW_WIDTH / gridCols;
    }
}

int main()
{
    bool isSpacePressed = false;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Agent Cell");
    SetTargetFPS(TARGET_FPS);
    int modifiedFps = TARGET_FPS;
    int row, col;

    int newGridCols = GRID_COLUMN_COUNT;
    int newGridRows = GRID_ROW_COUNT;

    int cellSize = 0;
    std::string genStr;

    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
    GuiSetStyle(DEFAULT, BASE_COLOR_NORMAL, 0x008000);
    

    CalculateCellSize(cellSize, newGridCols, newGridRows);

    Simulation simulation(GRID_COLUMN_COUNT, GRID_ROW_COUNT, cellSize);

    while (!WindowShouldClose())
    {
        // Event Handling
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            simulation.CalculateMouseOffset(row, col);
            simulation.ToggleCell(row, col);
        }
        else if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
            simulation.CalculateMouseOffset(row, col);
            simulation.ToggleCell(row, col);
        }


        if (IsKeyPressed(KEY_SPACE))
        {
            if (isSpacePressed)
            {
                simulation.Stop();
                SetWindowTitle("Agent Cell - Paused");
                isSpacePressed = false;
            }
            else
            {
                simulation.Start();
                SetWindowTitle("Agent Cell - Running");
                isSpacePressed = true;
            }
        }
        else if (IsKeyPressed(KEY_F))
        {
            modifiedFps += 2;
            SetTargetFPS(modifiedFps);
        }
        else if (IsKeyPressed(KEY_S))
        {
            if (modifiedFps > 5)
            {
                modifiedFps -= 2;
                SetTargetFPS(modifiedFps);
            }
        }
        else if (IsKeyPressed(KEY_C))
        {
            simulation.ClearGrid();
            simulation.ResetGenerationCount();
        }
        else if (IsKeyPressed(KEY_R))
        {
            simulation.CreateRandomState();
            simulation.ResetGenerationCount();
        }

        if (GuiButton(Rectangle{ 24, 1050, 150, 100}, "INCREASE")) {
            newGridCols += 10;
            newGridRows += 5;

            CalculateCellSize(cellSize, newGridCols, newGridRows);
            simulation.UpdateGridSize(newGridCols, newGridRows, cellSize);
        };

        if (GuiButton(Rectangle{ 180, 1050, 150, 100}, "DECREASE")) {
            newGridCols -= 10;
            newGridRows -= 5;

            CalculateCellSize(cellSize, newGridCols, newGridRows);
            simulation.UpdateGridSize(newGridCols, newGridRows, cellSize);
        };

        genStr = "CURRENT GENERATION:" + std::to_string(simulation.GetCurrentGeneration());
        GuiLabel(Rectangle{ 1000, 1050, 500, 120}, genStr.c_str());

        /// Updating State
        simulation.Update();

        // Drawing
        BeginDrawing();
        ClearBackground(BLACK);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}