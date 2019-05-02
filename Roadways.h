#ifndef __ROADWAYS_H__
#define __ROADWAYS_H__

#include "Intersection.h"
#include "Lane.h"
#include "Animator.h"
#include "TrafficLight.h"
#include "VehicleBase.h"

using namespace std;

/* This program serves as the container class for the intersection
 * and lanes. Thus it is the main class in hte simulation and is constructed
 * with a vector of parameters. Once it is constructed, you should advance the 
 * simulation by sending it a time which is then animatated and at the end 
 * clear the Roadways of vehicles.
 */

class Roadways{
    public:
        // constructor taking in a vector of parameters and initializing the traffic lights
        // and the animator
        Roadways(vector<double> inParams);

        // advances the simulation by advancing all the lanes and having one random arrival
        // in one of the lanes
        void advance(int t);

        // deallocate dynamic data pointers
        void clear();

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
