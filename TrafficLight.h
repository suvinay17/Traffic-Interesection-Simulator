/* Written by Suvinay Bothra on 16th April, 2019. Declaring the properties and attributes of the Traffic light in TrafficLight.h
 */
#ifndef __TrafficLight_H__
#define __TrafficLight_H__
using namespace std;

enum class LightColor {green, yellow, red};

class TrafficLight
{
	//private member variables
	private:

		int greenTime;
		int redTime;
		int yellowTime;

		LightColor status;
        int currentTime;
        // public methods	
	public:
        TrafficLight(int greenTime, int redTime, int yellowTime, LightColor status);
        ~TrafficLight(); 
		void setStatus(LightColor variable);
		LightColor getStatus();
        void updateLight(); 
        int getCurrentTime();

};
#endif
