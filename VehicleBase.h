//Authors: Allie, Ting, Suvinay
//Last edit: April 28, 2019
//Implementation of VehicleBase for final trafficJam, setting the vehicle type, size
//and direction 

#ifndef __VEHICLE_BASE_H__
#define __VEHICLE_BASE_H__

//enumerated type Direction for storing the direction of the vehicles
enum class Direction   {north, south, east, west};

//enumerated type Vehicle for sorting car type
enum class VehicleType {car, suv, truck};

class VehicleBase
{
   //creates public variables
   public:
      static int vehicleCount;

   //creates private variables
   private:
      int         vehicleID;
      VehicleType vehicleType;
      Direction   vehicleDirection;
      int         vehicleSize;

   //creates public variables
   public:
      VehicleBase(VehicleType type, Direction originalDirection);
      VehicleBase(const VehicleBase& other);
      ~VehicleBase();

      inline int getVehicleID() const { return this->vehicleID; }
      inline int getVehicleSize() const { return this->vehicleSize; }
      inline VehicleType getVehicleType() const { return this->vehicleType; }
      inline Direction   getVehicleOriginalDirection() const { return this->vehicleDirection; }
};

#endif

