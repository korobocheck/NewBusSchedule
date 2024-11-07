#ifndef TRIP_H
#define TRIP_H

#include <string>

class Trip {
public:
    Trip(const std::string& route, const std::string& date, const std::string& departureTime, const std::string& arrivalTime)
            : route(route), date(date), departureTime(departureTime), arrivalTime(arrivalTime) {}

    virtual ~Trip() = default;

    std::string getRoute() const { return route; }
    std::string getDate() const { return date; }
    std::string getDepartureTime() const { return departureTime; }
    std::string getArrivalTime() const { return arrivalTime; }

    void setRoute(const std::string& newRoute) { route = newRoute; }
    void setDate(const std::string& newDate) { date = newDate; }
    void setDepartureTime(const std::string& newDepartureTime) { departureTime = newDepartureTime; }
    void setArrivalTime(const std::string& newArrivalTime) { arrivalTime = newArrivalTime; }

protected:
    std::string route;
    std::string date;
    std::string departureTime;
    std::string arrivalTime;
};

#endif // TRIP_H