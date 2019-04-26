#ifndef __TrafficLight_CPP__
#define __TrafficLight_CPP__

#include "TrafficLight.h"

using namespace std;


TrafficLight::TrafficLight(int greenTime, int redTime, int yellowTime, LightColor status): greenTime(greenTime),
    redTime(redTime), yellowTime(yellowTime), status(status){
        if (status == LightColor::green)
            currentTime = greenTime;
        else if (status == LightColor::yellow)
            currentTime = yellowTime;
        else
            currentTime = redTime;
    }

TrafficLight::~TrafficLight() {}
LightColor TrafficLight::getStatus(){
    return this->status;
}
void TrafficLight::setStatus(LightColor variable){
    this->status = variable;

}
void TrafficLight::updateLight(){ 
    if(getStatus() == LightColor::green){
        currentTime--;
        if(currentTime == 0){
            setStatus(LightColor::yellow);
            currentTime = yellowTime;
        }
    }
    else if(getStatus() == LightColor::yellow){   
        currentTime--;
        if(currentTime == 0){
            setStatus(LightColor::red);
            currentTime = redTime;
        }
    }
    else{   
        currentTime--;
        if(currentTime == 0){
            setStatus(LightColor::green);
            currentTime = greenTime;
        }
    }
}

#endif





