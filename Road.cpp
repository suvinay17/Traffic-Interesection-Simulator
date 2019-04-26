/** Road.cpp written by Suvinay, serves as the road made up of sections for the traffic intersection project
 */
#ifndef __ROAD_CPP__
#define __ROAD_CPP__

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <VehicleBase.h>
#include <Road.h>
#include <Section.h>

Road::Road()
{
}


Road::~Road()
{
}

int Road::getLength()
{
  return section;

bool Road::getArrival(Vehicle v)
{
    if(Vehicle::v.getSize()==2)
     {
        if(!sections.at(0).Section::getOccupied() && !sections.at(1).Section::getOccupied())
          return true;
        return false;                 
     }
    else if(Vehicle::v.getSize()==3)
     {
        if(!sections.at(0).Section::getOccupied() && !sections.at(1).Section::getOccupied() && !sections.at(2).Section::getOccupied())
          return true;
        return false;
     }
     else if(Vehicle::v.getSize()==4)
     {
        if(!sections.at(0).Section::getOccupied() && !sections.at(1).Section::getOccupied()&& !sections.at(2).Section::getOccupied() && !sections.at(3).Section::getOccupied())       
           return true;
	return false;
     }
}
direction Road::getDirection()
{
  return direction;
};



void Road::advance()
{ 
  Section* c;
       for(int i = 0; i < vehicles.size(); i++)
         {
	   c = vehicles.at(i).getVehicle();
	   if(!(*c)+1.Section::getOccupied())
	     { 
	       Section::vehicle.at(i).setVehicle((*c)+1);
	     }	       
         }
};


     
        

	  

	
        
     

