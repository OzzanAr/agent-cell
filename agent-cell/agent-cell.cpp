#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <raymath.h>
#include "globals.hpp"
#include "simulation.hpp"
#include <algorithm>

int main()
{
    bool isSpacePressed = false;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Agent Cell");
    SetTargetFPS(TARGET_FPS);
    int modifiedFps = TARGET_FPS;
    int row, col;

    int cellSize =  WINDOW_WIDTH / GRID_ROW_COUNT;

    Simulation simulation(GRID_ROW_COUNT, GRID_COLUMN_COUNT, cellSize);

    while (!WindowShouldClose())
    {
        // Event Handling
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
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
        }
        else if (IsKeyPressed(KEY_R))
        {
            simulation.CreateRandomState();
        }

        /// Updating State
        simulation.Update();

        // Drawing
        BeginDrawing();
        ClearBackground(GRAY);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}