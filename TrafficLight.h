/* Written by Suvinay Bothra on 16th April, 2019. Declaring the properties and attributes of the Traffic light in TrafficLight.h
 */
#ifndef __TrafficLight_H__
#define __TrafficLight_H__
using namespace std;

class TrafficLight
{
	//private member variables
	private:
	

		int greenTime;
		int redTime;
		int yellowTime;
		enum status{open, occupied}
        // public methods	
	public:
		void updateLight();
		enum getStatus();

};
#endif
