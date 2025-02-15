#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include "globals.h"
#include "simulation.hpp"

int main()
{
    std::cout << "\nRunning Agent Cell\n";
    bool isEnterPressed = false;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Agent Cell");
    SetTargetFPS(TARGET_FPS);

    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);

    while (!WindowShouldClose())
    {
        // Event Handling
        if (IsKeyPressed(KEY_ENTER))
        {
            if (isEnterPressed)
            {
                simulation.Stop();
                SetWindowTitle("Agent Cell - Paused");
                isEnterPressed = false;
            }
            else
            {
                simulation.Start();
                SetWindowTitle("Agent Cell - Running");
                isEnterPressed = true;
            }
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