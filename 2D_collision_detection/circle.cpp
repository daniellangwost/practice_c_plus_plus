#include <iostream>
#include <cmath>
#include "circle.h"

Circle::Circle(double x, double y, double vx, double vy, double radius)
  : m_x {x}
  , m_y {y}
  , m_vx {vx}
  , m_vy {vy}
  , m_radius {radius}
{
}

void Circle::update(const double& timestep_length)
{
  m_x += timestep_length * m_vx;
  m_y += timestep_length * m_vy;
}

bool Circle::detectCollision(const Circle& c) const
{
  // use distance formula
  double distance = sqrt( (m_x - c.m_x) * (m_x - c.m_x) + (m_y - c.m_y) * (m_y - c.m_y) );
  return distance <= (m_radius + c.m_radius);
}
