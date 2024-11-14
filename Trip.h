#ifndef TRIP_H
#define TRIP_H

#include <string>
#include <string_view>

class Trip {
public:
    Trip(std::string_view route, std::string_view date, std::string_view departureTime, std::string_view arrivalTime)
            : route(route), date(date), departureTime(departureTime), arrivalTime(arrivalTime) {}

    virtual ~Trip() = default;

    std::string getRoute() const { return route; }
    std::string getDate() const { return date; }
    std::string getDepartureTime() const { return departureTime; }
    std::string getArrivalTime() const { return arrivalTime; }

    void setRoute(std::string_view newRoute) { route = newRoute; }
    void setDate(std::string_view newDate) { date = newDate; }
    void setDepartureTime(std::string_view newDepartureTime) { departureTime = newDepartureTime; }
    void setArrivalTime(std::string_view newArrivalTime) { arrivalTime = newArrivalTime; }

private:
    std::string route;
    std::string date;
    std::string departureTime;
    std::string arrivalTime;
};

#endif // TRIP_H