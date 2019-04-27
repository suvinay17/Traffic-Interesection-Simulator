#include "Section.h"

Section::Section(bool isO, bool atI, VehicleBase* v){
    isOccupied = isO;
    atIntersection = atI;
    vehiclePtr = v;
}
void Section::setPtr(VehicleBase* ptr){
    if (ptr != nullptr)
        isOccupied = true;
    else 
        isOccupied = false;

    vehiclePtr = ptr;
}
