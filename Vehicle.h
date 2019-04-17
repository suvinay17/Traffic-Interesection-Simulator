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
		bool probLeft;
		Vehicle* vehicle;


	public:
		void goRight();
		void goLeft();
		void goStraight();	

		Vehicle();
		~Vehicle() {}	
};

#endif