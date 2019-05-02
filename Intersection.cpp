/*Written by Allie, Ting, Suvinay. Last edit: arpil 28, 2019.
*Implementes the intersection portion infront of the lanes
*/
#include "Intersection.h"
#include "VehicleBase.h"

// constructor
Intersection::Intersection(){
    for (int i = 0; i < 4; i++){
        Section section(false, nullptr);
        sections.push_back(section);
        dontOverWrite.push_back(false);
    }
}

// advances the cars in the intersection based on the color of
// of the north south light which is passed in
void Intersection::advance(LightColor ns){ 

    // advance north and south bounds or east and west bounds
    if (ns == LightColor::green || ns == LightColor::yellow){
        sections[1].setPtr(sections[3].getPtr());
        sections[2].setPtr(sections[0].getPtr());
        
    }
    else if (ns == LightColor::red){
        sections[3].setPtr(sections[2].getPtr());
        sections[0].setPtr(sections[1].getPtr());
    }

    // checks which quadrants can't be overwritten because of advancing vehicles
    if (sections[3].getOccupied() && (sections[3].getPtr()->getVehicleOriginalDirection() == Direction::north)) 
        dontOverWrite[1] = true;
    else
        dontOverWrite[1] = false;

    if (sections[0].getOccupied() && sections[0].getPtr()->getVehicleOriginalDirection() == Direction::south)
        dontOverWrite[2] = true;
    else
        dontOverWrite[2] = false;
    
    if (sections[2].getOccupied() && sections[2].getPtr()->getVehicleOriginalDirection() == Direction::east)
        dontOverWrite[3] = true;
    else
        dontOverWrite[3] = false;

    if (sections[1].getOccupied() && sections[1].getPtr()->getVehicleOriginalDirection() == Direction::west)
        dontOverWrite[0] = true;
    else
        dontOverWrite[0] = false;
}

// places specified vehicle arrival in specified quadrant of the 
// intersection
void Intersection::arrival(VehicleBase* veh, int quadrant){
    sections[quadrant].setPtr(veh);
}

// checks if there is a vehicle in the given quadrant and the vehicle is
// leaving the intersection going the given direction
bool Intersection::isLeaving(int quadrant, Direction dir){
     return (sections[quadrant].getOccupied() && (sections[quadrant].getPtr()->getVehicleOriginalDirection() == dir));
}

// returns the vector of boolean values of whether the sections should be overwritten with an
// arrival or not, corresponding with each quadrant of the intersection
vector<bool> Intersection::getDontOverWrite(){
    return dontOverWrite;
}

// returns the vectos of vehicle pointers corresponding with each quadrant of the
// intersection
vector<VehicleBase*> Intersection::getVehicles(){
    vector<VehicleBase*> vs;
    for (int i = 0; i < (int)sections.size(); i++){
        vs.push_back(sections[i].getPtr());
    }

    return vs;
}
