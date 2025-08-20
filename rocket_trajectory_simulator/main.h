#include <string>
#include <vector>

#ifndef MAIN_H
#define MAIN_H

double get_positive_number(double upper, std::string name, std::string unit);

void write_data(std::vector<std::pair<double, double>>& data);

#endif