/* Written by Suvinay Bothra on 16th April, 2019.
 *Declaring the properties and attributes of the Traffic light in TrafficLight.h
 */
#ifndef __TrafficLight_H__
#define __TrafficLight_H__
using namespace std;

//enumerated type Light color for storing traffic light colors
enum class LightColor {green, yellow, red};

class TrafficLight
{
    //private member variables
	private:
        // the color times to be obtained from the constructor based on the input files. Determines how long each color of the traffic light will be on for.*/
		int greenTime;
		int redTime;
		int yellowTime;
        
        //status will store the current color of the traffic light
		LightColor status;
        
        //current time will store the updated time left for the current light color
        int currentTime;


    // public methods	
	public:
            //constructor
        	TrafficLight(int greenTime, int redTime, int yellowTime, LightColor status);
        
            //destructor
       	 	~TrafficLight();
            
            //mutator method for changing the traffic light color 
            void setStatus(LightColor variable);

            //accessor method for getting the current light color 
            LightColor getStatus();

            int getCurrentTime();

            //method containing the logic for changing the traffic light color
        	void updateLight(); 


};
#endif
