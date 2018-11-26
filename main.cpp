#include <iostream>
#include "city.hpp"
#include "tour.hpp"

int elite_index;

/**
 * Creates a vector of tours
 * @return Vector of tours
 */
vector<tour> populate_tours() {
    vector<tour> tours;
    for (int j = 0; j < POPULATION_SIZE; j++) { //make tours
        srand(time(NULL) + j);
        int name_value = 65;
        vector<city> city_tour;
        for (int i = 0; i < CITIES_IN_TOUR; i++) { //make cities
            char ascii_name = (char)name_value;
            string name(1, ascii_name);
            int x = rand() % MAP_BOUNDARY;
            int y = rand() % MAP_BOUNDARY;
            city tour_candidate(name, x, y);
            city_tour.push_back(tour_candidate);
            name_value++;
        }

        tour my_tour(city_tour);
        my_tour.shuffle_cities();
        for (auto &iter : my_tour.get_cities()) {
            cout << iter.get_name() << " " << iter.get_x() << " " << iter.get_y() << endl;
        }
        cout << " " << endl;
        tours.push_back(my_tour);
    }
    return tours;
}

/**
 * Returns the base distance which is the fittest tour
 * @param tour Vector of tours
 * @return Base distance
 */
double base_distance(vector<tour> tour) {
    double fittest_tour = tour.begin()->get_tour_distance();
    //cout << fittest_tour << endl;
    elite_index = 0; // tour index
    for(auto it = tour.begin() + 1; it != tour.end(); it++) {
        cout << it->get_tour_distance() << endl;
        if(it->get_tour_distance() < fittest_tour) {
            fittest_tour = it->get_tour_distance();
            elite_index = (int)(it - tour.begin());
        }

    }
    cout << tour.at(elite_index).determine_fitness() << endl; //testing function
//    cout << FITNESS_SCALE / fittest_tour << endl;
    return fittest_tour;
}

/**
 * Select parents for simple genetic algorithmn
 * @param tour_cities Vector of tours
 */
tour select_parents(vector<tour> tour_cities) {
    double fitness_sum = 0;
    double partial_sum = 0;
    for(auto city : tour_cities) {
        fitness_sum += city.determine_fitness();
    }
    srand(time(NULL));
    int random_num = rand() % (int)fitness_sum;
    for(auto a_tour: tour_cities) {
        partial_sum += a_tour.determine_fitness();
        if(partial_sum > random_num) {
            tour city_tour = a_tour;
            return city_tour;
        }
    }
}

void crossover();
void mutate();

/**
 * Drives the program
 * @return Integer
 */
int main() {
    vector<tour> tour = populate_tours();
//    double base = base_distance(tour);
    tour.at(4).contains_city("A"); // testing function
//    int iterations = 0;
//    while( / base < IMPROVEMENT_FACTOR && iterations <= ITERATIONS) {
//
//        iterations++;
//    }
    return 0;
}