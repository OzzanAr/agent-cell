#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include <deque>
#include "globals.h"


double lastUpdateTime = 0;

bool IsElementInDeque(Vector2 element, std::deque<Vector2> deque)
{
    for (unsigned int i = 0; i < deque.size(); i++)
    {
        if (Vector2Equals(deque[i], element))
        {
            return true;
        }
    }

    return false;
}

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

    Food(std::deque<Vector2> snakeBody)
    {
        Image img = LoadImage("assets/food.png");
        texture = LoadTextureFromImage(img);
        UnloadImage(img);
        position = GenerateRandomPosition(snakeBody);
    }

    ~Food()
    {
        UnloadTexture(texture);
    }

    void Draw()
    {
        DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
    }

    Vector2 GenerateRandomCell()
    {
        float x = GetRandomValue(0, cellCount - 1);
        float y = GetRandomValue(0, cellCount - 1);
        return {x, y};
    }

    Vector2 GenerateRandomPosition(std::deque<Vector2> snakeBody)
    {
        Vector2 position = GenerateRandomCell();

        while (IsElementInDeque(position, snakeBody))
        {
            position = GenerateRandomCell();
        }

        return position;
    }
};

class Snake
{
public:
    std::deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    Vector2 direction = {1, 0};
    bool addSegment = false;

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

    void Reset()
    {
        body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
        direction = {1, 0};
    }

    void Update()
    {
        body.push_front(Vector2Add(body[0], direction));
        if (addSegment)
        {
            addSegment = false;
        }
        else
        {
            body.pop_back();
        }
    }
};

class Game
{
public:
    Snake snake = Snake();
    Food food = Food(snake.body);
    bool isRunning = true;

    void Draw()
    {
        food.Draw();
        snake.Draw();
    }

    void Update()
    {
        if (isRunning)
        {
            snake.Update();
            CheckFoodCollision();
            CheckEdgeCollision();
            CheckTailCollision();
        }
    }

    void GameOver()
    {
        snake.Reset();
        food.position = food.GenerateRandomPosition(snake.body);
        isRunning = false;
    }

    void CheckFoodCollision()
    {
        if (Vector2Equals(snake.body[0], food.position))
        {
            food.position = food.GenerateRandomPosition(snake.body);
            snake.addSegment = true;
        }
    }

    void CheckEdgeCollision()
    {
        if (snake.body[0].x == cellCount || snake.body[0].x == -1)
        {
            GameOver();
        }

        if (snake.body[0].y == cellCount || snake.body[0].y == -1)
        {
            GameOver();
        }
    }

    void CheckTailCollision()
    {
        std::deque<Vector2> headlessBody = snake.body;
        headlessBody.pop_front();
        if (IsElementInDeque(snake.body[0], headlessBody))
        {
            GameOver();
        }
    }
};

void CheckMovement(Game &game)
{
    if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1)
    {
        game.snake.direction = {0, -1};
        game.isRunning = true;
    }
    else if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1)
    {
        game.snake.direction = {0, 1};
        game.isRunning = true;
    }
    else if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1)
    {
        game.snake.direction = {-1, 0};
        game.isRunning = true;
    }
    else if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1)
    {
        game.snake.direction = {1, 0};
        game.isRunning = true;
    }
}

int main()
{
    std::cout << "\nRunning Snake Game\n";
    int screenSize = 2 * offset + cellSize * cellCount;
    InitWindow(screenSize, screenSize, "Sanke Game");
    SetTargetFPS(60);

    Game game = Game();

    Rectangle borderRectangle = {
        (float)offset - 5,
        (float)offset - 5,
        (float)cellSize * cellCount + 10,
        (float)cellSize * cellCount + 10};

    while (!WindowShouldClose())
    {
        BeginDrawing();

        if (EventTriggered(0.2))
        {
            game.Update();
        }

        CheckMovement(game);

        ClearBackground(green);
        DrawRectangleLinesEx(borderRectangle, 5, darkGreen);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}