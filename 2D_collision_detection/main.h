#ifndef MAIN_H
#define MAIN_H
#include <vector>
#include "circle.h"

std::vector<std::pair<int,int>> checkCollisions(Circle& c1, Circle& c2, const int iterations, const double timestep_length);

#endif