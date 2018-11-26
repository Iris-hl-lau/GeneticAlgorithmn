#include <iostream>
#include "city.hpp"
#include "tour.hpp"

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

void set_elite_index() {

}

/**
 * Returns the base distance which is the fittest tour
 * @param tour Vector of tours
 * @return Base distance
 */
double base_distance(vector<tour> tour) {
    double fittest_tour = tour.begin()->get_tour_distance();
    //cout << fittest_tour << endl;
    int index = 0; // tour index
    for(auto it = tour.begin() + 1; it != tour.end(); it++) {
        cout << it->get_tour_distance() << endl;
        if(it->get_tour_distance() < fittest_tour) {
            fittest_tour = it->get_tour_distance();
            index = (int)(it - tour.begin());
        }

    }
    cout << tour.at(index).determine_fitness() << endl; //testing function
//    cout << FITNESS_SCALE / fittest_tour << endl;
    return fittest_tour;
}

//void selection(vector<tour> tour_vector) {
//    tour tmp = tour_vector[0];
//    swap(vector[], vector[]);
//    tour_vector.pop_back();
//}

/**
 * Drives the program
 * @return Integer
 */
int main() {
    vector<tour> tour = populate_tours();
    double base = base_distance(tour);
    tour.at(4).contains_city("A"); // testing function
    return 0;
}