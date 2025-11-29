#ifndef FLOCK_SIM_H
#define FLOCK_SIM_H
#include <raylib.h>

typedef struct {
    Vector2 position;
    Vector2 velocity;
    double health;
    double nutrient_uptake;
    double reproduction_rate;
    double lifespan;
    double radius;
    Color colour;
} Bacterium;


void generate_bacteria(int num_bodies,  Bacterium* bodies, int screen_width, int screen_height);

void shade_based_on_health(Bacterium* bacterium);

Vector2 next_position(Bacterium* bacterium, double delta_time);
double next_health(Bacterium* bacterium, double delta_time);

void time_step(Bacterium* bacteria, double delta_time);

#endif