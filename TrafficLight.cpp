#ifndef __TrafficLight_CPP__
#define __TrafficLight_CPP__
using namespace std;

TrafficLight::TrafficLight(int greenTime, int redTime, int yellowTime, enum status)
: greenTime(greenTime),
redTime(redTime),
yellowTime(yellowTime),
status(status)


TrafficLight::~TrafficLight() {};
TrafficLight:: status getStatus(){return this->status;};
TrafficLight:: private setStatus(status variable){this->variable;};
TrafficLight::void updateLight(){ 
if(getStatus() == green)
{
   greenTime--;
	if(greenTime == 0)
		setStatus(yellow);
}
else if(getStatus() == yellow)
{   yellowTime--
	if(yellowTime == 0)
   		setStatus(red);
}
else
{   redTime--;
	if(redTime == 0)
   		setStatus(green);
};

#endif





