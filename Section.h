#ifndef __SECTION__
#define __SECTION__

#include "VehicleBase.h"
using namespace std;

class Section {
	
	private: 
		bool isOccupied;
		bool atIntersection;
        VehicleBase* vehiclePtr;


	public:
        Section(bool isO, bool atI, VehicleBase* v);
		~Section(){}
		bool getOccupied(){
			return isOccupied;
		}
        void setPtr(VehicleBase* ptr);
		//car moves out of section and is no longer occupied
		/*void leave(){
            vehiclePtr = nullptr;
			isOccupied = false;
		}
		//car enters section and is now occupied
		void enter(VehicleBase* ptr){
			vehiclePtr = ptr;
            isOccupied = true;
		}*/
        VehicleBase* getPtr(){
            return vehiclePtr;
        }


				
};

#endif


//in constructor make either true or false roadway will be true vector of sections is false 
