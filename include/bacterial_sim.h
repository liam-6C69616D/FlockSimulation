#ifndef FLOCK_SIM_H
#define FLOCK_SIM_H
#include <raylib.h>

typedef struct {
    Vector2 position; // x,y position
    Vector2 velocity; // x,y velocity
    double health; // 0.0 to 1.0
    double nutrient_uptake; // -1 to 1
    double reproduction_rate; // 0 to 1
    double lifespan; // seconds
    double radius; // pixels
    Color colour;
} Bacterium;

extern int bacteria_count;

void generate_bacteria(int num_bodies,  Bacterium* bodies, int screen_width, int screen_height);

Color shade_based_on_health(Bacterium* bacterium);
bool die(Bacterium* bacterium);
Vector2 next_position(Bacterium* bacterium, double delta_time);
double next_health(Bacterium* bacterium, double delta_time);

Bacterium* time_step(Bacterium* bacteria, double delta_time);
Bacterium* remove_bacterium(Bacterium* bacteria, int* bacteria_count, int index);
Bacterium* reproduce_bacterium(Bacterium* bacteria, int* bacteria_count, int index);

#endif