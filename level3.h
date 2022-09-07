#include "raylib.h"
#include "level4.h"
int Level3(void)
{
    const int screenWidth = 840;
    const int screenHeight = 640;
    int count;
    int boxPositionY = screenHeight / 2 - 40;
    int boxPositionX = screenWidth / 2 - 40;
    int winposX = 0;
    int winposY = 0;
    while (!WindowShouldClose())
    {
        // Move up
        if (IsKeyDown(KEY_W))
            boxPositionY -= 10;
        // Move down
        if (IsKeyDown(KEY_S))
            boxPositionY += 10;
        // Move Left
        if (IsKeyDown(KEY_A))
            boxPositionX -= 10;
        // Move Right
        if (IsKeyDown(KEY_D))
            boxPositionX += 10;
        // Quit
        if (IsKeyDown(KEY_ESCAPE))
            break;

        BeginDrawing();

        ClearBackground(BLACK);
        DrawText("LEVEL 3", screenWidth / 2 - 40 + 120, screenHeight / 2 - 40 + 120, 30, BLUE);

        DrawRectangle(winposX, winposY, 80, 80, GREEN);
        DrawRectangle(screenWidth / 2 - 40, screenWidth / 2 - 40, 80, 80, LIGHTGRAY);
        DrawRectangle(boxPositionX, boxPositionY, 80, 80, MAROON);
        EndDrawing();
        if (boxPositionX == screenWidth / 2 - 40 && boxPositionY == screenHeight / 2 - 40)
        {
            count += 1;
            DrawText("Checkpoint Reached!", screenWidth / 2 - 60, screenHeight / 2 - 60 + 160, 30, GREEN);
        }
        if (boxPositionX == winposX && boxPositionY == winposY)
        {
            if (count <= 1)
            {
                DrawText("You need to unlock checkpoint first!", screenWidth / 2 - 60, screenHeight / 2 - 60 + 160, 30, RED);
            }
            else
            {
                ClearBackground(RAYWHITE);                
                DrawText("You rocked!, Click enetr to start the next Level ", screenWidth / 2 - 60, screenHeight / 2 - 60 + 160, 30, GREEN);
                if (IsKeyDown(KEY_ENTER))
                {
                    DrawText("Comming Soon!", screenWidth / 2 - 60, screenHeight / 2 - 100, 30, GREEN);
                }
            }
        }
    }
    return 0;
}