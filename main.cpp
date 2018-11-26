#include <iostream>
#include "city.hpp"
#include "tour.hpp"

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




int main() {
    vector<tour> tour = populate_tours();
    double fittest_tour = tour.begin()->get_tour_distance();
    cout << fittest_tour << endl;
    int index = 0; // tour index
    for(auto it = tour.begin() + 1; it != tour.end(); it++) {
        cout << it->get_tour_distance() << endl;
        if(it->get_tour_distance() < fittest_tour) {
            fittest_tour = it->get_tour_distance();
            index = (int)(it - tour.begin());
        }

    }
    cout << "" << tour.at(index).determine_fitness() << endl;
    cout << FITNESS_SCALE / fittest_tour << endl;
    tour.at(index).contains_city("A");
    return 0;
}