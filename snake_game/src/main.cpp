#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include <deque>
#include "globals.h"

using namespace std;

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }

    return false;
}

class Food
{
public:
    Vector2 position;
    Texture2D texture;

    Food()
    {
        Image img = LoadImage("assets/food.png");
        texture = LoadTextureFromImage(img);
        UnloadImage(img);
        position = GenerateRandomPosition();
    }

    ~Food()
    {
        UnloadTexture(texture);
    }

    void Draw()
    {
        DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
    }

    Vector2 GenerateRandomPosition()
    {
        float x = GetRandomValue(0, cellCount - 1);
        float y = GetRandomValue(0, cellCount - 1);

        return Vector2{x, y};
    }
};

class Snake
{
public:
    deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    Vector2 direction = {1, 0};

    void Draw()
    {
        for (unsigned int i = 0; i < body.size(); i++)
        {
            float x = body[i].x;
            float y = body[i].y;
            Rectangle segment = {
                x * cellSize,
                y * cellSize,
                (float)cellSize,
                (float)cellSize};
            DrawRectangleRounded(segment, 0.5, 6, darkGreen);
        }
    }

    void Update()
    {
        body.pop_back();
        body.push_front(Vector2Add(body[0], direction));
    }
};

class Game {
public:
    Snake snake = Snake();
    Food food = Food();

    void Draw() {
        food.Draw();
        snake.Draw();
    }

    void Update() {
        snake.Update();  
    }
};

void CheckMovement(Snake &snake){
    if (IsKeyPressed(KEY_UP) && snake.direction.y != 1)
    {
        snake.direction = {0, -1};
    }
    else if (IsKeyPressed(KEY_DOWN) && snake.direction.y != -1)
    {
        snake.direction = {0, 1};
    }
    else if (IsKeyPressed(KEY_LEFT) && snake.direction.x != 1)
    {
        snake.direction = {-1, 0};
    }
    else if (IsKeyPressed(KEY_RIGHT) && snake.direction.x != -1)
    {
        snake.direction = {1, 0};
    }
}

int main()
{
    cout << "\nRunning Snake Game\n";
    int screenSize = cellSize * cellCount;
    InitWindow(screenSize, screenSize, "Sanke Game");
    SetTargetFPS(60);

    Game game = Game();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        if (EventTriggered(0.2))
        {
            game.Update();
        }

        CheckMovement(game.snake);

        ClearBackground(green);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}