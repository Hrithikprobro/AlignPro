#include "raylib.h" 

int Level4(void)
{
    while(!WindowShouldClose())
    {
        DrawText("Coming soon", GetScreenWidth() / 2, GetScreenHeight() / 2, 30, GREEN);
    }
    CloseWindow();
    return 0;
}