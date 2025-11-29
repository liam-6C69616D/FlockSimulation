#include "bacterial_sim.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void generate_bacteria(int num_bodies, Bacterium* bacteria, int screen_width, int screen_height) {
    for (int i = 0; i < num_bodies; i++) {
        // place inside screen
        float x = (float)(rand() % screen_width);
        float y = (float)(rand() % screen_height);
        bacteria[i].position = (Vector2){ x, y };

        // small random velocity (pixels per second)
        float vx = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
        float vy = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
        bacteria[i].velocity = (Vector2){ vx * 50.0f, vy * 50.0f };

        // normalize health to 0..1
        bacteria[i].health = ((double) rand() / RAND_MAX);

        bacteria[i].nutrient_uptake =  ((double) rand() / RAND_MAX);
        bacteria[i].reproduction_rate =  ((double) rand() / RAND_MAX);
        bacteria[i].lifespan =  ((double) rand() / RAND_MAX);

        // make radius visible
        bacteria[i].radius = 2.0 + ((double) rand() / RAND_MAX) * 4.0; // 2..6 px

        shade_based_on_health(&bacteria[i]);
    }
}

void shade_based_on_health(Bacterium* bacterium) {
    double h = bacterium->health;
    if (h < 0.0) h = 0.0;
    if (h > 1.0) h = 1.0;

    int r = (int)(255.0 * (1.0 - h));
    int g = (int)(255.0 * h);
    int b = 0;

    bacterium->colour = (Color){ (unsigned char)r, (unsigned char)g, (unsigned char)b, 255 };
}