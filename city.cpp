//
// Created by Iris L on 2018-11-25.
//

#include "city.hpp"

city::city(string name, double x, double y) : name(name), x(x), y(y) {}

string city::get_name() {
    return this->name;
}

double city::get_x() {
    return this->x;
}

double city::get_y() {
    return this->y;
}