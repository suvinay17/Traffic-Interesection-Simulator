//Allie
#ifndef __VEHICLE__
#define __VEHICLE__

#include "VehicleBase.h"
#include "Lane.h"
#include "Section.h"
#include <vector>

class Vehicle : public VehicleBase {

	private: 
		int size;
		bool probRight;
		Lane* lane;
		Section* section;
		VehicleBase::VehicleType type;



	public:
		Vehicle(VehicleBase::VehicleType type, size, Section* startSection, bool probRight);
		Vehicle(const Vehicle& other);
		~Vehicle() {}	

		void goRight();
		void goStraight();

		int getSize();

		
};

#endif


//vehicle base = car, suv, truck should I make size just a product of that? 
//so should re