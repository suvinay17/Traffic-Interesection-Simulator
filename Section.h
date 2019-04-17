#ifndef __SECTION__
#define __SECTION__

#include "Lane"


class Section {
	
	private: 
		bool isOccupied(){}
		bool atIntersection(){}


	public:
		Section(){}
		~Section(){}
		bool isOccupied(){
			return isOccupied;
		}
		//car moves out of section and is no longer occupied
		void leave(){
			isOccupied = false;
		}
		//car enters section and is now occupied
		void enter(){
			isOccupied = true;
		}


				
};

#endif


//in constructor make either true or false roadway will be true vector of sections is false 