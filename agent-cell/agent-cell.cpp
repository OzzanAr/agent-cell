#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <raymath.h>
#include "globals.hpp"
#include "simulation.hpp"

int main()
{
    bool isSpacePressed = false;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Agent Cell");
    SetTargetFPS(TARGET_FPS);
    int modifiedFps = TARGET_FPS;

    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);

    while (!WindowShouldClose())
    {
        // Event Handling
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            Vector2 mousePos = GetMousePosition();
            int row = mousePos.y / CELL_SIZE;
            int col = mousePos.x / CELL_SIZE;
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