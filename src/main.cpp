#include "raylib.h"
#include "raymath.h"
#include <string>
#include "Player.h"

int main(void)
{
    const int WINDOW_WIDTH = 800,
              WINDOW_HEIGHT = 600;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Bromm - the game");

    Player player((float)WINDOW_WIDTH / 2, (float)WINDOW_HEIGHT / 2);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_RIGHT))
        {
            player.moveRight(2.0f);
        }
        if (IsKeyDown(KEY_LEFT))
        {
            player.moveLeft(2.0f);
        }
        if (IsKeyDown(KEY_UP))
        {
            player.moveUp(2.0f);
        }
        if (IsKeyDown(KEY_DOWN))
        {
            player.moveDown(2.0f);
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("BROMM", (WINDOW_WIDTH / 2) - 110, 80, 62, BLACK);

        DrawCircleV(player.getPosition(), 50, SKYBLUE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
