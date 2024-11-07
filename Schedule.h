#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "BusTrip.h"
#include <vector>

class Schedule {
public:
    void addTrip(const std::string& route, const std::string& date, const std::string& departureTime, const std::string& arrivalTime);
    void listTrips() const;
    void updateTrip(int index, const std::string& newRoute, const std::string& newDate, const std::string& newDepartureTime, const std::string& newArrivalTime);
    void deleteTrip(int index);
    void calculateFreeIntervals() const;
    const BusTrip* getTrip(int index) const;
    ~Schedule();

private:
    std::vector<BusTrip*> trips;
};

int timeToMinutes(const std::string& time);

#endif // SCHEDULE_H