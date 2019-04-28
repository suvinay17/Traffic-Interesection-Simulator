#ifndef __ROADWAYS_H__
#define __ROADWAYS_H__

#include "Intersection.h"
#include "Lane.h"
#include "Animator.h"
#include "TrafficLight.h"
#include "VehicleBase.h"

#include <chrono>
#include <random>

using namespace std;

class Roadways{
    public:
        Roadways(int numSections);

        void advance(int t);


    private:
        Intersection myIntersection;
        vector<Lane> myLanes;
        Animator myAnimator;
        vector<VehicleBase*> northBound;
        vector<VehicleBase*> southBound;
        vector<VehicleBase*> eastBound;
        vector<VehicleBase*> westBound;
        vector< vector<VehicleBase*> > bounds;

        int probCar = .6;
        int probSUV = .3;
        int numberOfSections;
        
        TrafficLight northSouthLight, eastWestLight;
        vector<TrafficLight> lights;

};
#endif
