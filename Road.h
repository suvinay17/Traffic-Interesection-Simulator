#ifndef __ROAD_H__
#define __ROAD_CPP__
using namespace std;

class Road
{
	private:
		enum direction{northbound, southbound, eastbound, westbound};
		int sections;
		vector<vehicle> vehicles;
		vector<sections> sections;

	public:
		enum getDirection();
		bool carArrival();
		void advance();
};
#endif
		
