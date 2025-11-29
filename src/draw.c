#include "bacterial_sim.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUMBER_OF_BACTERIA 2000

int main(void) {
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Orbits");

    srand(time(NULL));

    // Define the camera to look into our 3d world
    Camera camera = { 0 };
    camera.position = (Vector3){ 0.0f, 0.0f, 100.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Bacterium *bacteria = (Bacterium *) malloc(sizeof(Bacterium) * NUMBER_OF_BACTERIA);
    generate_bacteria(NUMBER_OF_BACTERIA, bacteria);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

            ClearBackground((Color) { 0, 0, 0, 255 });

            BeginMode3D(camera);

                for (int i = 0; i < NUMBER_OF_BACTERIA; i++) {
                    DrawSphere(bacteria[i].position, bacteria[i].radius, bacteria[i].colour);
                }

            EndMode3D();

            DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}