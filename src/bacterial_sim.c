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
        bacteria[i].velocity = (Vector2){ vx * 2.0f, vy * 2.0f };

        // normalize health to 0..1
        bacteria[i].health = ((double) rand() / RAND_MAX);

        bacteria[i].nutrient_uptake = ((double) rand() / RAND_MAX) * 2.0 - 1.0; // -1 to 1
        bacteria[i].reproduction_rate =  ((double) rand() / RAND_MAX);
        bacteria[i].lifespan =  ((double) rand() / RAND_MAX) * 100.0; // up to 100 seconds

        // make radius visible
        bacteria[i].radius = 2.0 + ((double) rand() / RAND_MAX) * 4.0; // 2..6 px

        bacteria[i].colour = shade_based_on_health(&bacteria[i]);
    }
}

Color shade_based_on_health(Bacterium* bacterium) {
    double h = bacterium->health;
    if (h < 0.0) h = 0.0;
    if (h > 1.0) h = 1.0;

    int r = (int)(255.0 * (1.0 - h));
    int g = (int)(255.0 * h);
    int b = 0;

    return (Color){ (unsigned char) r, (unsigned char) g, (unsigned char) b, 255 };
}

Vector2 next_position(Bacterium* bacterium, double delta_time) {
    Vector2 new_position;
    new_position.x = bacterium->position.x + bacterium->velocity.x * (float)delta_time;
    new_position.y = bacterium->position.y + bacterium->velocity.y * (float)delta_time;

    return new_position;
}

double next_health(Bacterium* bacterium, double delta_time) {
    double health_change = (bacterium->nutrient_uptake) * delta_time;
    return bacterium->health + health_change;
}

double next_lifespan(Bacterium* bacterium, double delta_time) {
    return bacterium->lifespan - delta_time;
}

bool die(Bacterium* bacterium) {
    return bacterium->health <= 0.0 || bacterium->lifespan <= 0.0;
}

void time_step(Bacterium* bacteria, double delta_time) {
    for (int i = 0; i < bacteria_count; i++) {
        bacteria[i].position = next_position(&bacteria[i], delta_time);
        bacteria[i].health = next_health(&bacteria[i], delta_time);
        bacteria[i].lifespan = next_lifespan(&bacteria[i], delta_time);
        bacteria[i].colour = shade_based_on_health(&bacteria[i]);

        if (die(&bacteria[i])) {
            remove_bacterium(bacteria, &bacteria_count, i);
            i--; // Adjust index after removal
        }
    }
}

void remove_bacterium(Bacterium* bacteria, int* bacteria_count, int index) {
    if (index < 0 || index >= *bacteria_count) {
        return; // Invalid index
    }

    // Shift bacteria to fill the gap
    for (int i = index; i < (*bacteria_count) - 1; i++) {
        bacteria[i] = bacteria[i + 1];
    }

    // Decrease the count of bacteria
    (*bacteria_count)--;
}