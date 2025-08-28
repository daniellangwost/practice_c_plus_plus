#include <cmath>
#include <vector>
#include <iostream>
#include "rocket.h"

Rocket::Rocket(double x, double y, double velocity, double angle, double target_altitude)
  : m_velocity {velocity}
  , m_angle {angle}
  , m_velocityX {cos(angle * (M_PI / 180)) * velocity} // horizontal component
  , m_velocityY {sin(angle * (M_PI / 180)) * velocity} // vertical component
  , m_x {x}
  , m_y {y}
  , m_target_altitude {target_altitude}
  , m_target_altitude_reached {false}
{
}

void Rocket::update(const double& timestep_seconds)
{
  double dy_per_step {m_velocityY * timestep_seconds - 0.5 * 9.81 * timestep_seconds * timestep_seconds};
  if ((m_y + dy_per_step > m_target_altitude) || (m_y > m_target_altitude))
  {
    std::cout << "REACHED TARGET AT ALTITUDE " << m_y << "\n"; 
    m_target_altitude_reached = true;
  }
  double dx = timestep_seconds * m_velocityX;
  m_x += dx;

  double dvelocityY = (-1) * timestep_seconds * 9.81; // acceleration due to gravity

  double dy = timestep_seconds * (m_velocityY + (dvelocityY / 2)); // average velocity from steps
  m_y += dy;

  m_velocityY += dvelocityY;
}

void Rocket::adjust_guidance(int remaining_corrections)
{
  std::cout << "Called adjust, velocityY is: " << m_velocityY << "\n";
  if (!m_target_altitude_reached)
  {
    double curr_v { sqrt( (m_velocityX * m_velocityX) + (m_velocityY * m_velocityY) ) };
    double curr_angle_rad { atan( m_velocityY / m_velocityX )};

    double max_height{};
    if (m_velocityY > 0)
    {
      max_height = m_y + ((curr_v * curr_v) * sin(curr_angle_rad) * sin(curr_angle_rad)) / (2 * 9.81);
    }
    
    double height_difference {m_target_altitude - max_height};

    if (height_difference > 0)
    {
      double adjustment_per_second { height_difference / remaining_corrections };
      if (m_velocityY - 9.81 > 0)
      {
        m_velocityY += adjustment_per_second;
      } else {
        m_velocityY += fabs(m_velocityY - 9.81);
      }
    }
  }
}

std::pair<double, double> Rocket::log()
{
  std::pair<double, double> position = {m_x, m_y};
  return position;
}