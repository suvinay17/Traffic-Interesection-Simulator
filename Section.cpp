//Authors: Allie, Ting, Suvinay
//Last edit: April 28, 2019
//Implementation of sections for lane, it holds vehiclePtr and the
// status for the section


#include "Section.h"

//constructor ititializes isOccupied, atIntersection, vehiclePtr
Section::Section(bool isO, bool atI, VehicleBase* v){
    isOccupied = isO;
    atIntersection = atI;
    vehiclePtr = v;
}

//sets the bool isOccupied
void Section::setPtr(VehicleBase* ptr){
    if (ptr != nullptr)
        isOccupied = true;
    else
        isOccupied = false;
    vehiclePtr = ptr;
}

//creates a destructor
Section::~Section(){}

//returns a pointer to the vehicle
VehicleBase* getPtr(){
    return vehiclePtr;
    }

//returns the status of the section
bool getOccupied(){
    return isOccupied;
    }
