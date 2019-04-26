#ifndef __VEHICLE_BASE_CPP__
#define __VEHICLE_BASE_CPP__

#include "VehicleBase.h"

using namespace std;

int VehicleBase::vehicleCount = 0;

VehicleBase::VehicleBase(VehicleType type, Direction direction)
    : vehicleID(VehicleBase::vehicleCount++), 
      vehicleType(type),
      vehicleDirection(direction)
{
    if (type == VehicleType::car)
        this->vehicleSize = 2;
    else if (type == VehicleType::suv)
        this->vehicleSize = 3;
    else
        this->vehicleSize = 4;

}

VehicleBase::VehicleBase(const VehicleBase& other)
    : vehicleID(other.vehicleID),
      vehicleType(other.vehicleType),
      vehicleDirection(other.vehicleDirection),
      vehicleSize(other.vehicleSize)
{}

VehicleBase::~VehicleBase() {}

#endif
