/**Written by Suvinay, Ting, and Allie. Date of last edit: 28th May 2019
 * Implementation of the TrafficLight for the intersection
 */
#ifndef __TrafficLight_CPP__
#define __TrafficLight_CPP__
#include "TrafficLight.h"
#include <iostream>

using namespace std;


// Constructor: Gets the times for each light color and the initial color status of the traffic light
TrafficLight::TrafficLight(int greenTime, int redTime, int yellowTime, LightColor status): greenTime(greenTime),
    redTime(redTime), yellowTime(yellowTime), status(status){
        if (status == LightColor::green)
            currentTime = greenTime;
        else if (status == LightColor::yellow)
            currentTime = yellowTime;
        else
            currentTime = redTime;
    }


// Destructor
TrafficLight::~TrafficLight() {}


//Getter method for getting the current light color of the traffic light
LightColor TrafficLight::getStatus(){
    return this->status;
}


//Setter method for changing the light color of the traffic light
void TrafficLight::setStatus(LightColor variable){
    this->status = variable;
}


//method with the logic for changing the traffic light colors 
void TrafficLight::updateLight(){ 
    //if the current traffic light color is green
    if(getStatus() == LightColor::green){
        //reduce current light color time by 1 for each second
        currentTime--;
        //if time left is 0 for the current traffic light color switch to the next light which in this case is yellow 
        if(currentTime == 0){ 
            setStatus(LightColor::yellow);
            currentTime = yellowTime;
        }
    }
    //if the current traffic light color is yellow
    else if(getStatus() == LightColor::yellow){
        //reduce the time left for the current light color by 1 for each second   
        currentTime--;
        //if the time left for the current traffic light color is 0, switch to the next color which is red
        if(currentTime == 0){
            setStatus(LightColor::red);
            currentTime = redTime;
        }
    }
    //the last option for the light color is red (if it is not yellow or green)
    else{   
        //decrement current time by one for the current color
        currentTime--;
        //if the current color time reaches 0 switch to the next traffic light color that is 0
        if(currentTime == 0){
            setStatus(LightColor::green);
            currentTime = greenTime;
        }
    }
}

int TrafficLight::getCurrentTime(){
    return currentTime;
}

#endif
