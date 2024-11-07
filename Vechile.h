// Vehicle.h
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
public:
    virtual ~Vehicle() = default;
    virtual std::string getVehicleType() const = 0;
};

#endif // VEHICLE_H