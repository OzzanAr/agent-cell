#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <raymath.h>
#include <algorithm>
#include <string>
#include <iostream>
#include "globals.hpp"
#include "simulation.hpp"
#include "utils.hpp"

void CalculateCellSize(int &cellSize, int gridCols, int gridRows) {
    cellSize = WINDOW_WIDTH + WINDOW_HEIGHT;

    if (cellSize * gridCols > WINDOW_WIDTH) {
        cellSize = WINDOW_WIDTH / gridCols;
    }
}

void UpdateWindowValues(int& windowWidth, int& windowHeight) {
    windowWidth = GetScreenWidth();
    windowHeight = GetScreenHeight();
}

void CalculateButtonPositions(float &btnWidth, float &btnHeight, float &btnY, float &spacing, float &btnXStart, int windowWidth, int windowHeight) {
	btnWidth = windowWidth * 0.1f;
	btnHeight = windowHeight * 0.08f;
	btnY = windowHeight - btnHeight - 20;

	spacing = windowWidth * 0.01f;
	btnXStart = (windowWidth - (3 * btnWidth + 2 * spacing)) / 2.0f;
}

int main()
{
    bool isSpacePressed = false;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Agent Cell");

    int windowWidth, windowHeight;
    UpdateWindowValues(windowWidth, windowHeight);

    float btnWidth, btnHeight, btnY, spacing, btnXStart;

    CalculateButtonPositions(btnWidth, btnHeight, btnY, spacing, btnXStart, windowWidth, windowHeight);

    SetTargetFPS(TARGET_FPS);
    int modifiedFps = TARGET_FPS;
    int row, col;
    
    int newGridCols = GRID_COLUMN_COUNT;
    int newGridRows = GRID_ROW_COUNT;

    int cellSize = 0;
    std::string genStr;

    CellType inputType = EMPTYCELL;

    std::string inputTypeStr = "SELECTED: " + std::to_string(inputType);

    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
    GuiSetStyle(DEFAULT, BASE_COLOR_NORMAL, 0x008000);

    CalculateCellSize(cellSize, newGridCols, newGridRows);

    Simulation simulation(GRID_COLUMN_COUNT, GRID_ROW_COUNT, cellSize);

    while (!WindowShouldClose())
    {
        UpdateWindowValues(windowWidth, windowHeight);
        // std::cout << "[LOG]: " << windowWidth << "x" << windowHeight << std::endl;

        // Event Handling
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            simulation.CalculateMouseOffset(row, col);
            simulation.ToggleCell(row, col, inputType);
        }
        else if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
            simulation.CalculateMouseOffset(row, col);
            simulation.ToggleCell(row, col, CellType::EMPTYCELL);
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

        if (GuiButton(Rectangle{ 24, 850, 150, 100}, "INCREASE")) {
            newGridCols += 10;
            newGridRows += 5;

            CalculateCellSize(cellSize, newGridCols, newGridRows);
            simulation.UpdateGridSize(newGridCols, newGridRows, cellSize);
        };

        if (GuiButton(Rectangle{ 180, 850, 150, 100}, "DECREASE")) {
            newGridCols -= 10;
            newGridRows -= 5;

            CalculateCellSize(cellSize, newGridCols, newGridRows);
            simulation.UpdateGridSize(newGridCols, newGridRows, cellSize);
        };

		CalculateButtonPositions(btnWidth, btnHeight, btnY, spacing, btnXStart, windowWidth, windowHeight);

        if (GuiButton(Rectangle{ btnXStart, btnY, btnWidth, btnHeight }, utils::EnumToString(BUNNY).c_str())) {
            inputType = BUNNY;
        }
        if (GuiButton(Rectangle{ btnXStart + btnWidth + spacing, btnY, btnWidth, btnHeight }, utils::EnumToString(FOX).c_str())) {
            inputType = FOX;
        }
        if (GuiButton(Rectangle{ btnXStart + 2 * (btnWidth + spacing), btnY, btnWidth, btnHeight }, utils::EnumToString(FOOD).c_str())) {
            inputType = FOOD;
        }

        inputTypeStr = "SELECTED: " + utils::EnumToString(inputType);

        // Labels
        genStr = "CURRENT GENERATION:" + std::to_string(simulation.GetCurrentGeneration());
        GuiLabel(Rectangle{ 1000, 1050, 500, 120}, genStr.c_str());

        GuiLabel(Rectangle{ 50, 50, 500, 120 }, "AGENT CELL");

        GuiLabel(Rectangle{ 50, 70, 500, 120 }, inputTypeStr.c_str());

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