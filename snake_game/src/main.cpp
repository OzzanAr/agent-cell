#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include <deque>
#include "globals.h"

class Game
{
public:
};

int main()
{
    std::cout << "\nRunning Agent Cell\n";

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Agent Cell");
    SetTargetFPS(TARGET_FPS);

    Game game = Game();

    while (!WindowShouldClose())
    {
        // Event Handling

        /// Updating State

        // Drawing
        BeginDrawing();
        ClearBackground(CUSTOM_GREY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}