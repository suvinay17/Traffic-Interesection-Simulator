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

bool Road::getArrival(probNorth, probSouth, probEast, probWest)
{
  float totalProb = rrand() % 1 + 0;
  if(totalProb <= .1)
    { //add as northbound
      return true;
    }
  else if(totalProb <=.2)
    { //add as south boun
      return true
    }
  else if(totalProb <= .35)
    {
     //add as eastbound
     return true;
    }
  else if(totalProb <= .5)
    {
     // add as westbound
     return true;
    }
  else
     return false; 
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


     
        

	  

	
        
     

