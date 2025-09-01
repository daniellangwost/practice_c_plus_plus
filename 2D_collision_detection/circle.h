#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
private:
  double m_x{};
  double m_y{};
  double m_vx{}; // horizontal velocity
  double m_vy{}; // vertical velocity
  double m_radius{};

public:
  Circle(double x, double y, double vx, double vy, double radius);
  
  bool detectCollision(const Circle& c) const;

  void update(const double& timestep_length);
};

#endif