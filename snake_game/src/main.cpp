#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include "globals.h"
#include "grid.hpp"

int main()
{
    std::cout << "\nRunning Agent Cell\n";

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Agent Cell");
    SetTargetFPS(TARGET_FPS);

    Grid grid(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);

    while (!WindowShouldClose())
    {
        // Event Handling

        /// Updating State

        // Drawing
        BeginDrawing();
        ClearBackground(GRAY);
        grid.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}