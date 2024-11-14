// BusTrip.h
#ifndef BUS_TRIP_H
#define BUS_TRIP_H

#include "Trip.h"
#include "Vechile.h"
#include <compare>
#include <string>

class BusTrip : public Trip, public Vehicle {
public:
    BusTrip(const std::string& route, const std::string& date, const std::string& departureTime, const std::string& arrivalTime)
            : Trip(route, date, departureTime, arrivalTime) {}

    std::string getType() const { return "Bus Trip"; }
    std::string getVehicleType() const override { return "Bus"; }

    bool operator==(const BusTrip& other) const {
        return departureTime == other.departureTime && arrivalTime == other.arrivalTime;
    }

    auto operator<=>(const BusTrip& other) const {
        if (auto cmp = departureTime <=> other.departureTime; cmp != 0) {
            return cmp;
        }
        return arrivalTime <=> other.arrivalTime;
    }
};

#endif // BUS_TRIP_H