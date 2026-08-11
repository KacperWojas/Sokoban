#include <raylib.h>

int main()
{
    InitWindow(640, 480, "raylib window");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("TEXT", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }
    return 0;
}
