#include <cmath>
#include <vector>
#include <iostream>
#include "rocket.h"

Rocket::Rocket(double x, double y, double velocity, double angle)
  : m_velocity {velocity}
  , m_angle {angle}
  , m_velocityX {cos(angle * (M_PI / 180)) * velocity} // horizontal component
  , m_velocityY {sin(angle * (M_PI / 180)) * velocity} // vertical component
  , m_x {x}
  , m_y {y}
{
}

void Rocket::update(const double& timestep_seconds)
{
  double dx = timestep_seconds * m_velocityX;
  m_x += dx;

  double dvelocityY = (-1) * timestep_seconds * 9.81; // acceleration due to gravity

  double dy = timestep_seconds * (m_velocityY + (dvelocityY / 2)); // average velocity from steps
  m_y += dy;

  m_velocityY += dvelocityY;
}

std::pair<double, double> Rocket::log()
{
  std::pair<double, double> position = {m_x, m_y};
  return position;
}