#ifndef __TrafficLight_CPP__
#define __TrafficLight_CPP__
using namespace std;

TrafficLight::TrafficLight(int greenTime, int redTime, int yellowTime, Status s)
: this.greenTime(greenTime),
this.redTime(redTime),
this.yellowTime(yellowTime),
this.st(s)


TrafficLight::~TrafficLight() {};
TrafficLight:: status getStatus(){return st;};
TrafficLight:: private setStatus(Status s){st = s;};
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





