#ifndef __ROAD_H__
#define __ROAD_CPP__
using namespace std;

class Road
{
	private:
		enum Direction{northbound, southbound, eastbound, westbound};
                Direction dir;
		int sections;
		vector<Vehicle> vehicles;
		vector<Section> sections;

	public:
		enum getDirection();
		bool carArrival();
		void advance();
};
#endif
		
