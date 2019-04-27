#ifndef __INTERSECTION_H__
#define __INTERSECTION_H__

#include "Section.h"
#include "TrafficLight.h"

#include <vector>

class Intersection{
    public:
        Intersection();
        
        void greenLane();
        void yellowLane();
        void redLane();
        void advance(LightColor ns);
        void arrival(VehicleBase* veh, int quadrant);
        bool isLeaving(int quadrant, Direction dir);
        vector<bool> getDontOverWrite();
        vector<int> getLastSection();
        vector<VehicleBase*> getVehicles();

    private:
        vector<Section> sections;
        vector<bool> dontOverWrite;
        vector<int> lastSection;
        
};
#endif
