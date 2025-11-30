#include "bacterial_sim.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int bacteria_count = 500;

int main(void) {
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Orbits");

    srand(time(NULL));

    
    Bacterium *bacteria = (Bacterium *) malloc(sizeof(Bacterium) * bacteria_count);
    generate_bacteria(bacteria_count, bacteria, screenWidth, screenHeight);

    SetTargetFPS(120);

    while (!WindowShouldClose()) {
        BeginDrawing();

            ClearBackground((Color) { 0, 0, 0, 255 });

            for (int i = 0; i < bacteria_count; i++) {
                DrawCircle(bacteria[i].position.x, bacteria[i].position.y, bacteria[i].radius, bacteria[i].colour);
            }

            bacteria = time_step(bacteria, GetFrameTime());

            DrawFPS(10, 10);


        EndDrawing();
    }

    CloseWindow();

    free(bacteria);

    return 0;
}