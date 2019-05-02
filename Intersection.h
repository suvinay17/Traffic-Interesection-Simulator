/*Written by Allie, Ting, Suvinay. Date of last edit: April 28, 2019.
 * .h file for declaring the attributes of the intersection infront of the lanes
 */
#ifndef __INTERSECTION_H__
#define __INTERSECTION_H__

#include "Section.h"
#include "TrafficLight.h"

#include <vector>

class Intersection{
    public:
        // constructor
        Intersection();     
        
        // advances the cars in the intersection based on the color of
        // of the north south light which is passed in
        void advance(LightColor ns);
        
        // places specified vehicle arrival in specified quadrant of the 
        // intersection
        void arrival(VehicleBase* veh, int quadrant);
        
        // checks if there is a vehicle in the given quadrant and the vehicle is
        // leaving the intersection going the given direction
        bool isLeaving(int quadrant, Direction dir);
        
        // returns the vector of boolean values of whether the sections should be overwritten with an
        // arrival or not, corresponding with each quadrant of the intersection
        vector<bool> getDontOverWrite();
        
        // returns the vectos of vehicle pointers corresponding with each quadrant of the
        // intersection
        vector<VehicleBase*> getVehicles();

    private:
        vector<Section> sections;
        vector<bool> dontOverWrite;
};
#endif
