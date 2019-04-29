//Authors: Allie, Ting, Suvinay
//Last edit: April 28, 2019
//Implementation of  sections for lane, it holds vehiclePtr and the
// status for the section

#ifndef __SECTION__
#define __SECTION__

#include "VehicleBase.h"
using namespace std;

class Section {

	// creates private variables
	private:
		bool isOccupied;
		bool atIntersection;
    VehicleBase* vehiclePtr;

	// creates public variables
	public:
    	Section(bool isO, bool atI, VehicleBase* v);
		~Section();
		bool getOccupied();
    	void setPtr(VehicleBase* ptr);
    	VehicleBase* getPtr();

};

#endif
