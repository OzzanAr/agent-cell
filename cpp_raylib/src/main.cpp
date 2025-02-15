#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include "globals.h"
#include "simulation.hpp"

int main()
{
    std::cout << "\nRunning Agent Cell\n";

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Agent Cell");
    SetTargetFPS(TARGET_FPS);

    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);
    simulation.SetCellValue(5, 29, 1);
    simulation.SetCellValue(6, 0, 1);
    simulation.SetCellValue(5, 0, 1);
    simulation.SetCellValue(4, 0, 1);

    std::cout << "\nLive Neighbours:" << simulation.CountLiveNeighbors(5, 29) << std::endl;

    while (!WindowShouldClose())
    {
        // Event Handling

        /// Updating State

        // Drawing
        BeginDrawing();
        ClearBackground(GRAY);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}