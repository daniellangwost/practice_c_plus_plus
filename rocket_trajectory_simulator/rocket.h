#ifndef ROCKET_H
#define ROCKET_H
#include <iostream>

class Rocket
{
private:
  double m_velocity{};
  double m_angle{};
  double m_velocityX {};
  double m_velocityY {};
  double m_x{};
  double m_y{};

public:
  Rocket(double x, double y, double velocity, double angle);

  void update(const double& timestep_seconds);

  std::pair<double, double> log();

  double get_y() { return m_y; }
};

#endif