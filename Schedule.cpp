#include "schedule.h"
#include <iostream>
#include <algorithm>

int timeToMinutes(const std::string& time) {
    int hours = std::stoi(time.substr(0, 2));
    int minutes = std::stoi(time.substr(3, 2));
    return hours * 60 + minutes;
}

void Schedule::addTrip(const std::string& route, const std::string& date, const std::string& departureTime, const std::string& arrivalTime) {
    BusTrip* newTrip = new BusTrip(route, date, departureTime, arrivalTime);
    trips.push_back(newTrip);
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

void Schedule::updateTrip(int index, const std::string& newRoute, const std::string& newDate, const std::string& newDepartureTime, const std::string& newArrivalTime) {
    if (index < 0 || index >= trips.size()) {
        std::cerr << "Неверный индекс!" << std::endl;
        return;
    }
    trips[index]->setRoute(newRoute);
    trips[index]->setDate(newDate);
    trips[index]->setDepartureTime(newDepartureTime);
    trips[index]->setArrivalTime(newArrivalTime);
    std::cout << "Рейс обновлен: " << newRoute << " на " << newDate << " с отправлением в " << newDepartureTime << " и прибытием в " << newArrivalTime << std::endl;
}

void Schedule::deleteTrip(int index) {
    if (index < 0 || index >= trips.size()) {
        std::cerr << "Неверный индекс!" << std::endl;
        return;
    }
    delete trips[index];
    trips.erase(trips.begin() + index);
    std::cout << "Рейс удален." << std::endl;
}

void Schedule::calculateFreeIntervals() const {
    if (trips.empty()) {
        std::cout << "Нет запланированных рейсов." << std::endl;
        return;
    }

    std::vector<const BusTrip*> sortedTrips(trips.begin(), trips.end());
    std::sort(sortedTrips.begin(), sortedTrips.end(), [](const BusTrip* a, const BusTrip* b) {
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
    if (index < 0 || index >= trips.size()) {
        return nullptr;
    }
    return trips[index];
}

Schedule::~Schedule() {
    for (auto trip : trips) {
        delete trip;
    }
}