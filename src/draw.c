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

    
    Bacterium *bacteria = (Bacterium *) malloc(sizeof(Bacterium) * NUMBER_OF_BACTERIA);
    int bacteria_count = NUMBER_OF_BACTERIA;
    generate_bacteria(bacteria_count, bacteria, screenWidth, screenHeight);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

            ClearBackground((Color) { 0, 0, 0, 255 });          

            for (int i = 0; i < bacteria_count; i++) {
                DrawCircle(bacteria[i].position.x, bacteria[i].position.y, bacteria[i].radius, bacteria[i].colour);
            }

            DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}