/** Lane.cpp written by Suvinay,Ting, and Allie. Last edited on 28th April, 2019
* Serves as the lane made up of sections for the traffic intersection project.
*/
#ifndef __LANE_CPP__
#define __LANE_CPP__

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Lane.h"


// Constuctor for setting up lane based on the number of sections based on the input file and the direction in which the cars of that lane will go in
Lane::Lane(int numSections, Direction d)
{
    for (int i = 0; i < numSections; i++)
    {
        Section section(false, false, NULL);
        sections.push_back(section);
    }

    direction = d;
    buffer = 0;
}


//destructor
Lane::~Lane()
{
}



void Lane::carArrival(Direction dir, bool hit, VehicleBase* arrival)
{
    if (buffer > 0 && hit)
        return;
    
    
    if (hit == true){

        vehicles.push_back(arrival);

        buffer = arrival->getVehicleSize();

        sections[0].setPtr((vehicles.back()));

        hit = false;
    }
    else if (buffer > 0)
        sections[0].setPtr((vehicles.back()));
    else
        sections[0].setPtr(nullptr);

   
    cout << "vehicles" << endl;
    for (int i = 0; i < vehicles.size(); i++)
        cout << &vehicles[i] << endl;
 

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

        int i = 0;

        while (i < sections.size() - 4){ //largest vehicle is car
            int j = i + 1;

            while (sections[i].getOccupied() && sections[j].getOccupied() && j != sections.size() - 2){
                j++;
            }
            //cout << "j: " << j << endl;
            //cout << "i: " << i << endl;

            if (j == i+1)
                i = j;
            else if (j != sections.size() - 2){ // reached end
                for (int k = j; k >= i; k--){
                    sections[k].setPtr(sections[k-1].getPtr());
                }
                if (buffer > 0)
                    buffer--;

                cout << "here" << endl;

                break;
            }
            else 
                break;
        }

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
