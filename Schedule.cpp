#include <vector>
#include <ranges>
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include "Schedule.h"

void Schedule::calculateFreeIntervals() const {
    if (trips.empty()) {
        std::cout << "Нет запланированных рейсов." << std::endl;
        return;
    }

    std::vector<const BusTrip*> sortedTrips;
    for (const auto& trip : trips) {
        sortedTrips.push_back(trip.get());
    }

    std::ranges::sort(sortedTrips, [](const auto& a, const auto& b) {
        return a->getDepartureTime() < b->getDepartureTime();
    });

    std::cout << "Свободные промежутки времени между рейсами:" << std::endl;

    for (size_t i = 0; i < sortedTrips.size() - 1; ++i) {
        int arrival = timeToMinutes(sortedTrips[i]->getArrivalTime());
        int nextDeparture = timeToMinutes(sortedTrips[i + 1]->getDepartureTime());

        if (nextDeparture > arrival) {
            int freeTime = nextDeparture - arrival;
            std::cout << "Между рейсом " << sortedTrips[i]->getRoute() << " и " << sortedTrips[i + 1]->getRoute()
                      << ": " << freeTime << " минут" << std::endl;
        }
    }
}