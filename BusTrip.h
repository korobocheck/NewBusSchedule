#ifndef BUS_TRIP_H
#define BUS_TRIP_H

#include "Trip.h"

class BusTrip : public Trip {
public:
    BusTrip(const std::string& route, const std::string& date, const std::string& departureTime, const std::string& arrivalTime)
            : Trip(route, date, departureTime, arrivalTime) {}

    bool operator==(const BusTrip& other) const {
        return departureTime == other.departureTime;
    }

    bool operator<(const BusTrip& other) const {
        if (departureTime != other.departureTime)
            return departureTime < other.departureTime;
        return arrivalTime == other.arrivalTime;
    }

    bool operator>(const BusTrip& other) const {
        if (departureTime != other.departureTime)
            return departureTime > other.departureTime;
        return arrivalTime == other.arrivalTime;
    }
};

#endif // BUS_TRIP_H