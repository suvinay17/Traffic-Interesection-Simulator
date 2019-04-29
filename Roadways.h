#ifndef __ROADWAYS_H__
#define __ROADWAYS_H__

#include "Intersection.h"
#include "Lane.h"
#include "Animator.h"
#include "TrafficLight.h"
#include "VehicleBase.h"

using namespace std;

class Roadways{
    public:
        Roadways(vector<double> inParams);

        void advance(int t);

    private:
        Intersection myIntersection;
        vector<double> inputParameters;
        vector<Lane> myLanes;
        Animator myAnimator;
        vector<VehicleBase*> northBound;
        vector<VehicleBase*> southBound;
        vector<VehicleBase*> eastBound;
        vector<VehicleBase*> westBound;
        vector< vector<VehicleBase*> > bounds;

        
        
        TrafficLight northSouthLight, eastWestLight;
        vector<TrafficLight> lights;

};
#endif
