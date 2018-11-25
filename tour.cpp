//
// Created by Iris L on 2018-11-23.
//

#include "tour.hpp"

tour::tour(vector<city> tour_cities) : tour_cities(tour_cities) {}

void tour::shuffle_cities() {
    for (int i = 0; i <= SHUFFLES; i++) {
        srand(time(NULL) + i);
        int first = rand() % CITIES_IN_TOUR;
        int second = rand() % CITIES_IN_TOUR;
        swap(tour_cities[first], tour_cities[second]);
    }
}

double tour::get_distance(city a, city b) {
    double x_diff = abs(b.get_x() - a.get_x());
    double y_diff = abs(b.get_y() - a.get_y());
    double distance = sqrt(pow(x_diff, 2) + pow(y_diff, 2));
    return distance;
}

int tour::get_tour_distance(tour a_tour) {
    double total_tour_distance = 0;
    vector<city> tour = a_tour.get_cities();
    for(auto iter = tour.begin(); iter != tour.end(); iter++) {
        city &a = *iter;
        city &b = *(iter + 1);
        total_tour_distance += get_distance(a, b);

        if(iter == tour.end() - 1) {
            a = *tour.begin();
            total_tour_distance += get_distance(a, b);
        }
    }
    return total_tour_distance;
}

vector<city> tour::get_cities() {
    return tour_cities;
}
