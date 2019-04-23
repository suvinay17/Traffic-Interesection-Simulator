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


direction Road::getDirection()
{
  return direction;
}


void Road::advance()
{ 
  Section* c;

  if(TrafficLight::getStatus() == green || TrafficLight::getStatus() == yellow)
    {
       for(int i = 0; i < vehicles.size(); i++)
         {
	   c = vehicles.at(i).getVehicle();
	   if(!(*c)+1.Section::getOccupied()  && Section::)
	     { 
	       Section::vehicle.at(i).setVehicle((*c)+1);
	     }	
       TrafficLight::updateLight();
         }
    }

  else
     {
        if(!Section::getOccupied())
	{
	  //logic to move ahead
	}
	TrafficLight::updateLight();
        }
     }
};
