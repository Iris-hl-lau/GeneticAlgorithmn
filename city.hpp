//
// Created by Iris L on 2018-11-23.
//

#ifndef GENETICALGORITHMN_CITY_HPP
#define GENETICALGORITHMN_CITY_HPP
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class city {
private :
    string name; //Unique city name
    double x; //Longitude
    double y; //Latitude

public:
    city(string name, double x, double y); // x and y must be between 0 and 1000
    string get_name();
    double get_x();
    double get_y();
};


#endif //GENETICALGORITHMN_CITY_HPP
