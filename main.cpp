#include "raylib.h"
#include "level2.h"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
void EndScreen();
int main(void)
{
    // Variables
    const int screenWidth = 840;
    const int screenHeight = 640;

    bool x = true;
    int boxPositionY = screenHeight / 2 - 40;
    int boxPositionX = screenWidth / 2 - 40;
    int winposX = 0;
    int winposY = 0;

    // Making Window Resizable
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    // Initializing the window
    InitWindow(screenWidth, screenHeight, "AlignPro");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose())
    {
        if (x)
        {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            
            DrawText("AlignPro", boxPositionX, boxPositionY, 100, BLACK);
            DrawText("Click Enter to continue", boxPositionX, boxPositionY + 100, 20, GREEN);
            EndDrawing();
            if (IsKeyDown(KEY_ENTER))
                x = false;
            continue;
        }

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

        // Check for Wining position
        if (boxPositionX == winposX && boxPositionY == winposY)
        {

            // If in winpos display "Congrats! You won"
            BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawText("Congrats! You won ", screenWidth / 2 - 50, screenHeight / 2 - 50, 40, GREEN);
            if(IsKeyDown(KEY_ENTER))
                Level2(); 
                


            EndDrawing();
        
            continue;
        }


        // Drawing player and win pos square
        BeginDrawing();

        ClearBackground(SKYBLUE);
        DrawText("LEVEL 1", screenWidth / 2 - 40 + 120, screenHeight / 2 - 40 + 120, 30, BLACK);
        
        DrawRectangle(winposX, winposY, 80, 80, GREEN);
        DrawRectangle(boxPositionX, boxPositionY, 80, 80, MAROON);

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;

}
