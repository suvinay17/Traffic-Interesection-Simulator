#ifndef __LANE_H__
#define __LANE_H__
using namespace std;

#include "VehicleBase.h"
#include "Section.h"
#include <vector>
#include "TrafficLight.h"

class Lane
{
	public:
        Lane(int numSections, Direction d);
        ~Lane();

		Direction getDirection();
		int carArrival(Direction dir, bool hit);
        void carArrival(VehicleBase* veh);

		void advance();
        void advanceRed();

        vector<VehicleBase*> getVehicles();
        
        bool beforeIntersection();
        
        bool getContinuedArrival();
        void setContinuedArrival(bool val);
	
        VehicleBase* getContinuedArrivee();
        void setContinuedArrivee(VehicleBase* veh);
    
    private:
		int numberOfSections;
		vector<VehicleBase> vehicles;
		vector<Section> sections;
        Direction direction;
        int buffer;
        bool continuedArrival = false;
        VehicleBase* continuedArrivee;

};
#endif
		
