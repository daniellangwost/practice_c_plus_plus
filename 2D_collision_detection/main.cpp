#include <iostream>
#include <vector>
#include "circle.h"
#include "main.h"

int main()
{
  // Circle c (x, y, vx, vy, radius)
  Circle c1 {-5, -5, 3, 3, 7};
  Circle c2 {5, 5, -2, -2, 5};

  constexpr int iterations {100};
  constexpr double timestep_length = 0.1;

  std::vector<std::pair<int,int>> collisions {checkCollisions(c1, c2, iterations, timestep_length)};

  for (auto collision : collisions)
  {
    std::cout << "Collision from step " << collision.first << " to " << collision.second << "\n";
  }

  return 0;
}

std::vector<std::pair<int,int>> checkCollisions(Circle& c1, Circle& c2, const int iterations, const double timestep_length)
{
  std::vector<std::pair<int, int>> collisions {};
  std::pair<int, int> current_collision {-1, -1}; // sentinel values to check if pair is set
  bool previous_timestep_collision {false};

  for (int i{0}; i < iterations; ++i)
  { 
    if (c1.detectCollision(c2)) // circles are colliding
     {
      if (!previous_timestep_collision) // collision just started
      {
        current_collision.first = i;
        previous_timestep_collision = true;
      }
     } else {
      if (previous_timestep_collision) // collision just ended
      {
        current_collision.second = i;
        collisions.push_back(current_collision);
        current_collision = {-1, -1};
        previous_timestep_collision = false;
      }
     }
    c1.update(timestep_length);
    c2.update(timestep_length);
  }

  if (previous_timestep_collision) // collision during last timestep
  {
    current_collision.second = (iterations-1); // -1 used for zero indexing
    collisions.push_back(current_collision);
  }

  return collisions;
}