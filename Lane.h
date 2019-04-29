#ifndef __LANE_H__
#define __LANE_H__
using namespace std;

#include "VehicleBase.h"
#include "Section.h"
#include <vector>
#include "TrafficLight.h"

class Lane
{       //public members
	public:

                //Constructor
        	Lane(int numSections, Direction d);
                //Destructor
       	        ~Lane();
		//Accessor for direction
		Direction getDirection();
		//Method for spawning a car 
		void carArrival(Direction dir, bool hit, VehicleBase* arrival);
		//Method for sending car from intersection to the next lane
        	void carArrival(VehicleBase* veh);
		//Method for moving the cars forward when the light is green
		void advance();
		//Method for moving cars not touching the intersection forward during red and yellow light
        	void advanceRed();
		//Accessor Method for getting vehicles
        	vector<VehicleBase*> getVehicles();
		//Boolean Value indicating if a vehicle is touching an interesection
               	bool beforeIntersection();
		//
               	bool getContinuedArrival();
                //
        	void setContinuedArrival(bool val);
		//
	       	VehicleBase* getContinuedArrivee();
		
        	void setContinuedArrivee(VehicleBase* veh);
    
        //private members
        private:
                //number of sections in the lane
		int numberOfSections;
                //vector of vehicles in the lane
		vector<VehicleBase*> vehicles;
		//vector of sections in the lane
		vector<Section> sections;
		//direction the vehicles are heading in the lane
       	 	Direction direction;
		//buffer used to 
        	int buffer;
        	bool continuedArrival = false;
        	VehicleBase* continuedArrivee;

};
#endif
		
