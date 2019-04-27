#ifndef __ROADWAYS_H__
#define __ROADWAYS_H__

#include "Intersection.h"
#include "Lane.h"
#include "Animator.h"
#include "TrafficLight.h"

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

        int numberOfSections;
        
        TrafficLight northSouthLight, eastWestLight;
        vector<TrafficLight> lights;

};
#endif
