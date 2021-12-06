#include "raylib.h"

int main()
{
    const int windowWidth{384};
    const int windowHeight{384};
    InitWindow(windowWidth, windowHeight, "Victor's Top Down");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos{0.0, 0.0};
    const float mapScale{4.0f};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();

    return 0;

}
