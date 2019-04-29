//Authors: Allie, Ting, Suvinay
//Last edit: April 28, 2019
//Implementation of VehicleBase for final trafficJam, setting the vehicle type, size
//and direction 

#ifndef __VEHICLE_BASE_CPP__
#define __VEHICLE_BASE_CPP__

#include "VehicleBase.h"
using namespace std;

//creates a counter for the number of vehicles
int VehicleBase::vehicleCount = 0;

//constructor initializing vehicle type, size and direction
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

//default constructor
VehicleBase::VehicleBase(const VehicleBase& other)
    : vehicleID(other.vehicleID),
      vehicleType(other.vehicleType),
      vehicleDirection(other.vehicleDirection),
      vehicleSize(other.vehicleSize) {}

//deconstructor
VehicleBase::~VehicleBase() {}

#endif
