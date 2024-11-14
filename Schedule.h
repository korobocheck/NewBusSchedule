#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "BusTrip.h"
#include <vector>
#include <memory>
#include <string_view>

class Schedule {
public:
    Schedule() = default;

    // Copy constructor
    Schedule(const Schedule& other) {
        for (const auto& trip : other.trips) {
            trips.push_back(std::make_unique<BusTrip>(*trip));
        }
    }

    // Copy assignment operator
    Schedule& operator=(const Schedule& other) {
        if (this != &other) {
            trips.clear();
            for (const auto& trip : other.trips) {
                trips.push_back(std::make_unique<BusTrip>(*trip));
            }
        }
        return *this;
    }

    // Move constructor
    Schedule(Schedule&& other) noexcept = default;

    // Move assignment operator
    Schedule& operator=(Schedule&& other) noexcept = default;

    void addTrip(std::string_view route, std::string_view date, std::string_view departureTime, std::string_view arrivalTime);
    void listTrips() const;
    void updateTrip(int index, std::string_view newRoute, std::string_view newDate, std::string_view newDepartureTime, std::string_view newArrivalTime);
    void deleteTrip(int index);
    void calculateFreeIntervals() const;
    const BusTrip* getTrip(int index) const;

private:
    std::vector<std::unique_ptr<BusTrip>> trips;
};

int timeToMinutes(std::string_view time);

#endif // SCHEDULE_H