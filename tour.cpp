//
// Created by Iris L on 2018-11-23.
//

#include "tour.hpp"
#include <iostream>
using namespace std;

/**
 * Constructor of tour
 * @param tour_cities  Vector of cities
 */
tour::tour(vector<city> tour_cities) : tour_cities(tour_cities) {}

/**
 * Shuffles cities in the tour
 */
void tour::shuffle_cities() {
    for (int i = 0; i <= SHUFFLES; i++) {
        srand(time(NULL) + i);
        int first = rand() % CITIES_IN_TOUR;
        int second = rand() % CITIES_IN_TOUR;
        swap(tour_cities[first], tour_cities[second]);
    }
}

/**
 * Returns the distance between two cities
 * @param a First cuty
 * @param b Second city
 * @return Distance of two cities
 */
double tour::get_distance(city a, city b) {
    double x_diff = abs(b.get_x() - a.get_x());
    double y_diff = abs(b.get_y() - a.get_y());
    double distance = sqrt(pow(x_diff, 2) + pow(y_diff, 2));
    return distance;
}

/**
 * Returns the total distance of a tour
 * @return  Total distance of a tour
 */
double tour::get_tour_distance() {
    double total_tour_distance = 0;
    city &start = *tour_cities.begin();
    city &end = *(tour_cities.end() - 1);
    for(auto iter = tour_cities.begin(); iter != tour_cities.end() - 1; iter++) {
        city &a = *iter;
        city &b = *(iter + 1);
        total_tour_distance += get_distance(a, b);
    }
    total_tour_distance += get_distance(start, end);
    return total_tour_distance;
}

/**
 * Returns the fitness of a tour
 * @return Fitness of a tour
 */
double tour::determine_fitness() {
    double fitness = FITNESS_SCALE / get_tour_distance();
    return fitness;
}

/**
 * Returns a boolean of whether a city exists in tour
 * @param name Name of city to search for
 * @return boolean
 */
bool tour::contains_city(string name) {
    for (auto iter = tour_cities.begin(); iter != tour_cities.end(); iter++) {
        if(iter->get_name() == name) {
            return true;
        }
    }
    return false;
}

/**
 * Returns a vector of cities
 * @return Vector of cities
 */
vector<city> tour::get_cities() {
    return tour_cities;
}
