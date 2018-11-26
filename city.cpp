//
// Created by Iris L on 2018-11-25.
//

#include "city.hpp"

/**
 * City constructor
 * @param name  Name of city
 * @param x  Longitude of city
 * @param y  Latitude of city
 */
city::city(string name, double x, double y) : name(name), x(x), y(y) {}

/**
 * Getter of city name
 * @return Name of city
 */
string city::get_name() {
    return this->name;
}

/**
* Getter of city longitude
* @return Longitude of city
*/
double city::get_x() {
    return this->x;
}

/**
 * Getter of city latitude
 * @return Latitude of city
 */
double city::get_y() {
    return this->y;
}