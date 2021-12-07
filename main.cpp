#include "raylib.h"
#include "raymath.h"

int main()
{
    const int windowWidth{384};
    const int windowHeight{384};
    InitWindow(windowWidth, windowHeight, "Victor's Top Down");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos{0.0, 0.0};
    const float mapScale{4.0f};
    const float speed{4.0};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 direction{};
        if (IsKeyDown(KEY_A))
        {
            direction.x -= 1.0;
        }
        if (IsKeyDown(KEY_D))
        {
            direction.x += 1.0;
        }
        if (IsKeyDown(KEY_W))
        {
            direction.y -= 1.0;
        }
        if (IsKeyDown(KEY_S))
        {
            direction.y += 1.0;
        }
        if (Vector2Length(direction) != 0.0)
        {
            // set mapPos = mapPos - direction
            mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
        }

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();

    return 0;

}
