/** Lane.cpp written by Suvinay, Ting, and Allie. Last edited on 28th April, 2019
* Serves as the lane made up of sections for the traffic intersection project.
*/
#ifndef __LANE_CPP__
#define __LANE_CPP__

#include <vector>
#include "Lane.h"

// Constuctor for setting up lane based on the number of sections based on the input file and the direction in which the cars of that lane will go in
Lane::Lane(int numSections, Direction d)
{
    for (int i = 0; i < numSections; i++)
    {
        Section section(false, nullptr);
        sections.push_back(section);
    }

    direction = d;
    buffer = 0; // initially no arriving vehicle
}


//destructor
Lane::~Lane() {} 

//method that spawns a new vehicle based on the direction
void Lane::carArrival(Direction dir, bool hit, VehicleBase* arrival)
{
    // don't do anything if the lane is full
    if (isFull()){
        // delete pointer if there is a vehicle arriving
        if (hit) 
            delete arrival;
        return;
    }
    
    // if there is a vehicle in the process of arriving 
    // and another vehicle arrives through the newest one out
    if (buffer > 0 && hit){
        delete arrival;
        
        sections[0].setPtr((vehicles.back()));
        buffer--;
        return;
    }
    
    // continuing arrival of a vehicle
    if (buffer > 0){
        sections[0].setPtr((vehicles.back()));
        buffer--;
    }
    else if (hit == true){
        vehicles.push_back(arrival);

        buffer = arrival->getVehicleSize();

        sections[0].setPtr((vehicles.back()));
        buffer--;

        hit = false;
    }
    else
        sections[0].setPtr(nullptr);
}

//method 
void Lane::carArrival(VehicleBase* veh){
    sections[0].setPtr(veh);
}

//method that returns all the vehicles in one lane
vector<VehicleBase*> Lane::getVehicles(){
    vector<VehicleBase*> vs;
    
    for (int i = 0; i < (int)sections.size(); i++){
        vs.push_back(sections[i].getPtr());
    }

    return vs;
}

//method that returns the directions the vehicles are heading in, in the specific lane.
Direction Lane::getDirection()
{
  return direction;
}


//method used to advance cars
void Lane::advance()
{ 
    for(int i = sections.size() - 1; i > 0; i--){
        sections[i].setPtr(sections[i-1].getPtr());
    }

    sections[0].setPtr(nullptr);
}


//method with logic to advance cars that are not touching the intersection to move ahead during red and yellow lights
void Lane::advanceRed(){  
    if (!sections[(int)sections.size() - 1].getOccupied())
        advance();
    else{
        // with more cars, advance only up to a stop point where section is empty
        int i = (int)sections.size() - 1;

        while (i > 0 && sections[i].getOccupied()){
            i--;
        }

        if (i == 0)
            return;

        for (int j = i; j > 0; j--)
            sections[j].setPtr(sections[j-1].getPtr());

        sections[0].setPtr(nullptr);
    }
}

//method that checks if a vehicle is touching an intersection
bool Lane::beforeIntersection(){
    return sections[sections.size()-1].getOccupied();
}

//Accessor method for seeing if there is a vehicle entering from the intersection
bool Lane::getContinuedArrival(){
    return continuedArrival;
}

//Changes value of whether there is a vehicle entering from the intersection
void Lane::setContinuedArrival(bool val){
    continuedArrival = val;
}

//Accessor method for getting the vehicle arriving from the intersection
VehicleBase* Lane::getContinuedArrivee(){
    return continuedArrivee;
}

//Sets the vehicle that is arriving from the intersection
void Lane::setContinuedArrivee(VehicleBase* veh){
    continuedArrivee = veh;
}

// deallocate vehicle pointers 
void Lane::clear(){
   for (vector<VehicleBase*>::iterator it = vehicles.begin(); it != vehicles.end();){
       delete *it;  
       it = vehicles.erase(it);
   }
}

// helper method for determining when the lane is full and cannot accept
// any more arrivals
bool Lane::isFull(){
    for (int i = 0; i < (int)sections.size(); i++)
        if (!sections[i].getOccupied())
            return false;

    return true;
}

#endif
