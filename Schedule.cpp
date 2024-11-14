#include "Schedule.h"
#include <iostream>
#include <algorithm>
#include <string_view>

int timeToMinutes(std::string_view time) {
    int hours = std::stoi(std::string(time.substr(0, 2)));
    int minutes = std::stoi(std::string(time.substr(3, 2)));
    return hours * 60 + minutes;
}

void Schedule::addTrip(std::string_view route, std::string_view date, std::string_view departureTime, std::string_view arrivalTime) {
    auto newTrip = std::make_unique<BusTrip>(route, date, departureTime, arrivalTime);
    trips.push_back(std::move(newTrip));
    std::cout << "Рейс добавлен: " << route << " на " << date << " с отправлением в " << departureTime << " и прибытием в " << arrivalTime << std::endl;
}

void Schedule::listTrips() const {
    std::cout << "Текущие рейсы:" << std::endl;
    for (const auto& trip : trips) {
        std::cout << "Маршрут: " << trip->getRoute()
                  << ", Дата: " << trip->getDate()
                  << ", Отправление: " << trip->getDepartureTime()
                  << ", Прибытие: " << trip->getArrivalTime() << std::endl;
    }
}

void Schedule::updateTrip(int index, std::string_view newRoute, std::string_view newDate, std::string_view newDepartureTime, std::string_view newArrivalTime) {
    if (index < 0 || index >= static_cast<int>(trips.size())) {
        std::cerr << "Неверный индекс!" << std::endl;
        return;
    }
    trips[index]->setRoute(std::string(newRoute));
    trips[index]->setDate(std::string(newDate));
    trips[index]->setDepartureTime(std::string(newDepartureTime));
    trips[index]->setArrivalTime(std::string(newArrivalTime));
    std::cout << "Рейс обновлен: " << newRoute << " на " << newDate << " с отправлением в " << newDepartureTime << " и прибытием в " << newArrivalTime << std::endl;
}

void Schedule::deleteTrip(int index) {
    if (index < 0 || index >= static_cast<int>(trips.size())) {
        std::cerr << "Неверный индекс!" << std::endl;
        return;
    }
    trips.erase(trips.begin() + index);
    std::cout << "Рейс удален." << std::endl;
}

void Schedule::calculateFreeIntervals() const {
    if (trips.empty()) {
        std::cout << "Нет запланированных рейсов." << std::endl;
        return;
    }

    std::vector<const BusTrip*> sortedTrips;
    for (const auto& trip : trips) {
        sortedTrips.push_back(trip.get());
    }

    std::sort(sortedTrips.begin(), sortedTrips.end(), [](const auto& a, const auto& b) {
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

const BusTrip* Schedule::getTrip(int index) const {
    if (index < 0 || index >= static_cast<int>(trips.size())) {
        return nullptr;
    }
    return trips[index].get();
}