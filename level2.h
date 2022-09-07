#include "raylib.h"
#include "level3.h"

int Level2(void)
{
    const int screenWidth = 840;
    const int screenHeight = 640;
    int count = 0;
    int boxPositionY = screenHeight / 2 - 40;
    int boxPositionX = screenWidth / 2 - 40;
    int winposX = 0;
    int winposY = 0;

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

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
        DrawText("LEVEL 2", screenWidth / 2 - 40 + 120, screenHeight / 2 - 40 + 120, 30, BLUE);

        DrawRectangle(winposX, winposY, 80, 80, GREEN);
        DrawRectangle(screenWidth / 2 - 40, winposY, 80, 80, LIGHTGRAY);
        DrawRectangle(boxPositionX, boxPositionY, 80, 80, MAROON);

        EndDrawing();
        if (boxPositionX == screenWidth / 2 - 40 && boxPositionY == winposY){
            count += 1;
            DrawText("Checkpoint Reached!", screenWidth / 2 - 60, screenHeight / 2 - 60 + 160, 30, GREEN);
            
        }

        if (boxPositionX == winposY && boxPositionY == winposY)
        {
            if (count <= 1)
            {
                DrawText("You need to unlock checkpoint first", screenWidth / 2 - 60, screenHeight / 2 - 100, 30, RED);
                continue;
            }
            else
            {
                ClearBackground(RAYWHITE);
                DrawText("You won!, Click Enter to start Next Level", screenWidth / 2 - 60, screenHeight / 2 - 60 + 160, 30, GREEN);
                if (IsKeyPressed(KEY_ENTER))
                {
                    Level3();
                }
            }
        }

        
    }
    CloseWindow();
    return 0;
}