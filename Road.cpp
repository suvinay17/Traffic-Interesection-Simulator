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

Road::Road(direction dir, int sections, std::vector<section> sections, std::vector<vehicle> vehicles)
{
   dir=;// declare direction enum
   numsections=sections;
   for(int i = 0; i < numsections; i++) {
   sections.push_back(Section section);
 }	
//learn what to do for vehicles
   

}


Road::~Road()
{
}


void Road:advance()
{

  if(TrafficLight::getStatus()==green)
    {
       
         for(int k=0; k < numSection-1; k++)
         {
             
        
	    if(!Section::getOcuppied())
	    {
                sections.at(k+1)=sections.at(k);// addVehicle will take care of 0th section
	
               }  
	}   
        
}	
}
TrafficLight::updateLight();
 else if(getStatus()==yellow)
    {
}
TrafficLight::updateLight();
 else{
}
TrafficLight::updateLight();
}
