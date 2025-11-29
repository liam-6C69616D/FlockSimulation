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
        bacteria[i].colour = (Color) { rand() % 256, rand() % 256, rand() % 256, 255 };
    }
}