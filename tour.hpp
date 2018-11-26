//
// Created by Iris L on 2018-11-23.
//

#ifndef GENETICALGORITHMN_TOUR_HPP
#define GENETICALGORITHMN_TOUR_HPP

#include "city.hpp"
#include <ctime>
#include <cstdlib>
#include <cmath>

#define CITIES_IN_TOUR 32
#define POPULATION_SIZE 32
#define SHUFFLES 64
#define ITERATIONS 1000
#define MAP_BOUNDARY 1000
#define PARENT_POOL_SIZE 5
#define MUTATION_RATE 15
#define NUMBER_OF_PARENTS
#define NUMBER_OF_ELITES 1
#define FITNESS_SCALE 100000

class tour {
private:
    vector<city> tour_cities;
public:
    explicit tour(vector<city> tour_cities);
    void shuffle_cities();
    double get_distance(city a, city b);
    double get_tour_distance();
    double determine_fitness(); //short tours have better fitness
    void select_parents();
    void crossover();
    void mutate();
    bool contains_city(string name);
    vector<city> get_cities();
};





#endif //GENETICALGORITHMN_TOUR_HPP
