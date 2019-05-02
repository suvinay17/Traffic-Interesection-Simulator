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


//method that spawns a new vehicle based on the direction
void Lane::carArrival(Direction dir, bool hit, VehicleBase* arrival)
{
    //cout << (int)direction << ": " << buffer << endl;
    
    if (isFull()){
        if (hit)
            delete arrival;
        return;
    }
    
    if (buffer > 0 && hit){
        delete arrival;
        
        sections[0].setPtr((vehicles.back()));
        buffer--;
        return;
    }
    
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


    // if full return -1

    //cout << "vehicles" << endl;
    //for (int i = 0; i < vehicles.size(); i++)
        //cout << &vehicles[i] << endl;

 

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
void Lane::advanceRed(){ // with more cars, advance only up to stop point
    if (!sections[(int)sections.size() - 1].getOccupied())
        advance();
    else{

        /*int i = 0;

        while (i < (int)sections.size() - 4){ //largest vehicle is truck 
            int j = i + 1;

            while (sections[i].getOccupied() && sections[j].getOccupied() && j != (int)sections.size() - 2){
                j++;
            }

            if (j == 1){
                sections[j].setPtr(sections[i].getPtr());
                break;
            }
            else if (j == i+1)
                i = j;
            else if (j != (int)sections.size() - 2){ // reached end
                for (int k = j; k >= i; k--){
                    if (k == 0)
                        break;

                    sections[k].setPtr(sections[k-1].getPtr());
                }
                if (buffer > 0)
                    buffer--;

                //cout << "here" << endl;

                break;
            }
            else 
                break;
        }*/

        int i = (int)sections.size() - 1;

        while (i > 0 && sections[i].getOccupied()){
            i--;
        }

        if (i == 0)
            return;

        for (int j = i; j > 0; j--){
            sections[j].setPtr(sections[j-1].getPtr());
            
          //  if (buffer > 0)
          //     buffer--;
        }

        sections[0].setPtr(nullptr);
    }
}


//method that checks if a vehicle is touching an interesection
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

void Lane::clear(){
   for (vector<VehicleBase*>::iterator it = vehicles.begin(); it != vehicles.end();){
       delete *it;  
       it = vehicles.erase(it);
   }
}


bool Lane::isFull(){
    for (int i = 0; i < (int)sections.size(); i++)
        if (!sections[i].getOccupied())
            return false;

    return true;
}

#endif
