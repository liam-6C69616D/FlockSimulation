#ifndef FLOCK_SIM_H
#define FLOCK_SIM_H
#include <raylib.h>

typedef struct {
    Vector3 position;
    Vector3 velocity;
    double health;
    double nutrient_uptake;
    double reproduction_rate;
    double lifespan;
    double radius;
    Color colour;
} Bacterium;

void generate_bacteria(int num_bodies, Bacterium* bodies);

#endif