/* Written by Allie, Ting, Suvinay. Last edited April 28th, 2019.
 * Declaring the lane which consists of sections and the direction and plays
 * the role of both the preceding and following lane.
 */
#ifndef __LANE_H__
#define __LANE_H__
using namespace std;

#include "VehicleBase.h"
#include "Section.h"
#include <vector>
#include "TrafficLight.h"

class Lane
{   
    //public member
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

        //Accessor method for seeing if there is a vehicle entering from the intersection
        bool getContinuedArrival();
                
        //Changes value of whether there is a vehicle entering from the intersection
        void setContinuedArrival(bool val);
		
        //Accessor method for getting the vehicle arriving from the intersection
        VehicleBase* getContinuedArrivee();
		
        //Sets the vehicle that is arriving from the intersection
        void setContinuedArrivee(VehicleBase* veh);

        // method for deallocating the pointers of the vehicles at the end
        void clear();
    
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
		
        //buffer used to continue inserting an arrival of a vehicle lane 
        int buffer;

        //initially no arrival into lane from intersection
        bool continuedArrival = false;
        
        //vehicle that is arriving into lane from intersection
        VehicleBase* continuedArrivee;

        // helper method for determining when the lane is full and cannot accept
        // any more arrivals
        bool isFull();
};
#endif
		
