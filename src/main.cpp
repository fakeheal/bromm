#include <iostream>
#include <string>
#include "raylib.h"
#include "raymath.h"
#include "Player.h"
#include "EnvironmentItem.h"

#define G 400
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void UpdatePlayer(Player &player, EnvironmentItem *environment, int environmentItemsCount, float delta);

int main(void)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Bromm - the game");

    Player player(PLAYER_SIZE / 2, 440, PLAYER_SIZE, PLAYER_SIZE);

    EnvironmentItem environment[] = {
        EnvironmentItem(0.0f - WINDOW_WIDTH / 2, (float)(WINDOW_HEIGHT - 120.0f), (float)WINDOW_WIDTH * 2, 120.0f, true, LIGHTGRAY),
    };

    int environmentItemsCount = sizeof(environment) / sizeof(EnvironmentItem);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        float deltaTime = GetFrameTime();
        UpdatePlayer(player, environment, environmentItemsCount, deltaTime);

        ClearBackground(RAYWHITE);

        for (int i = 0; i < environmentItemsCount; i++)
        {
            DrawRectangleRec(environment[i].getRectangle(), environment[i].getColor());
        }

        player.draw();

        // std::cout << player << std::endl;

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void UpdatePlayer(Player &player, EnvironmentItem *environment, int environmentItemsCount, float delta)
{

    if (IsKeyDown(KEY_LEFT))
        player.setPositionX(player.getPosition().x - delta * PLAYER_MOVE_SPEED);
    if (IsKeyDown(KEY_RIGHT))
    {
        player.setPositionX(player.getPosition().x + delta * PLAYER_MOVE_SPEED);
    }

    if (IsKeyDown(KEY_SPACE) && player.getCanJump())
    {
        player.setSpeed(-PLAYER_JUMP_SPEED);
        player.setCanJump(false);
    }

    bool didHitObstacle = false;
    for (int i = 0; i < environmentItemsCount; i++)
    {
        EnvironmentItem envItem = environment[i];

        if (
            envItem.getIsBlocking() &&
            envItem.getPosition().x <= player.getPosition().x &&
            envItem.getPosition().x + envItem.getDimensions().x >= player.getPosition().x &&
            envItem.getPosition().y >= player.getPosition().y &&
            envItem.getPosition().y <= player.getPosition().y + player.getSpeed() * delta)
        {
            didHitObstacle = true;
            player.setSpeed(0.0f);
            player.setPosition(player.getPosition().x, envItem.getPosition().y);
        }
    }

    if (player.getPosition().x > WINDOW_WIDTH)
    {
        player.setPositionX(0);
    }

    if (player.getPosition().x < 0)
    {
        player.setPositionX(WINDOW_WIDTH);
    }

    if (!didHitObstacle)
    {
        player.setPositionY(player.getPosition().y + player.getSpeed() * delta);
        player.setSpeed(player.getSpeed() + (G * delta));
        player.setCanJump(false);
    }
    else
        player.setCanJump(true);
}
