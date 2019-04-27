/** Lane.cpp written by Suvinay, serves as the road made up of sections for the traffic intersection project
 */
#ifndef __LANE_CPP__
#define __LANE_CPP__

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Lane.h"

Lane::Lane(int numSections, Direction d)
{
    for (int i = 0; i < numSections; i++)
    {
        Section section(false, false, NULL);
        sections.push_back(section);
    }

    direction = d;
}


Lane::~Lane()
{
}

int Lane::carArrival(Direction dir, bool hit)
{
    if (hit == true){
    
        VehicleBase arrival(VehicleType::truck, dir);

        vehicles.push_back(arrival);

        buffer = arrival.getVehicleSize();

        sections[0].setPtr(&(vehicles.back()));

        hit = false;
    }
    else if (buffer > 0)
        sections[0].setPtr(&(vehicles.back()));
    else
        sections[0].setPtr(nullptr);

    // if full return -1
    //
    cout << "vehicles" << endl;
    for (int i = 0; i < vehicles.size(); i++)
        cout << &vehicles[i] << endl;
 

    return 1;
}

void Lane::carArrival(VehicleBase* veh){
    sections[0].setPtr(veh);
    
}

vector<VehicleBase*> Lane::getVehicles(){
    vector<VehicleBase*> vs;
    
    for (int i = 0; i < sections.size(); i++){
        vs.push_back(sections[i].getPtr());
    }

    return vs;
}


Direction Lane::getDirection()
{
  return direction;
}


void Lane::advance()
{ 
    for(int i = sections.size() - 1; i > 0; i--){
        sections[i].setPtr(sections[i-1].getPtr());
    }

    if (buffer > 0){
        //arriving  = true;
        //sections[0].setPtr(&(vehicles.front()));
        buffer--;
    }
}

void Lane::advanceRed() // with more cars, advance only up to stop point
{ 
    if (!sections[sections.size() - 1].getOccupied())
        advance();
    else{
        int stopPoint = sections.size() - (sections[sections.size()-1].getPtr())->getVehicleSize();

        for (int i = stopPoint -1; i > 0; i--){
            if (!sections[i].getOccupied() || sections[i].getPtr() == sections[i-1].getPtr())
                sections[i].setPtr(sections[i-1].getPtr());
        }
    /*
        for(int i = sections.size() - 2; i > 0; i--){
            if (sections[stopPoint].getPtr() != sections[sections.size() -1].getPtr()){// && !sections[i].getOccupied()))
                sections[i].setPtr(sections[i-1].getPtr());
                if (buffer > 0){
                    //arriving  = true;
                    //sections[0].setPtr(&(vehicles.front()));
                    buffer--;
                }
            }
        }*/

    }
}

bool Lane::beforeIntersection(){
    return sections[sections.size()-1].getOccupied();
}

bool Lane::getContinuedArrival(){
    return continuedArrival;
}


void Lane::setContinuedArrival(bool val){
    continuedArrival = val;
}
	
VehicleBase* Lane::getContinuedArrivee(){
    return continuedArrivee;
}

void Lane::setContinuedArrivee(VehicleBase* veh){
    continuedArrivee = veh;
}

#endif
