#include "bacterial_sim.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void generate_bacteria(int num_bodies, Bacterium* bacteria) {
    for (int i = 0; i < num_bodies; i++) {
        bacteria[i].position = (Vector3){ (double)(rand() % (100 - (-100) + 1) + (-100)), (double)(rand() % (100 - (-100) + 1) + (-100)), (double)(rand() % (100 - (-100) + 1) + (-100)) };
        bacteria[i].velocity = (Vector3){ (double)(rand() % (5 - (-5) + 1) + (-5)), (double)(rand() % (5 - (-5) + 1) + (-5)), (double)(rand() % (5 - (-5) + 1) + (-5)) };
        bacteria[i].health =  ((double) rand() / RAND_MAX) * 15.0;
        bacteria[i].nutrient_uptake =  ((double) rand() / RAND_MAX);
        bacteria[i].reproduction_rate =  ((double) rand() / RAND_MAX);
        bacteria[i].lifespan =  ((double) rand() / RAND_MAX);
        bacteria[i].radius = ((double) rand() / RAND_MAX) / 5.0;
        shade_based_on_health(&bacteria[i]);
    }
}

void shade_based_on_health(Bacterium* bacterium) {
    double r = (unsigned char)(255 * (1 - bacterium->health)); // Red decreases as health increases
    double g = (unsigned char)(255 * bacterium->health); // Green increases as health increases
    double b = 0; // Blue remains 0

    bacterium->colour = (Color) { (unsigned char)r, (unsigned char)g, (unsigned char)b, 255 };
}