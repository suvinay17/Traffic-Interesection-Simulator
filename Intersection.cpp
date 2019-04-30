/*Written by Allie, Ting, Suvinay. Last edit: arpil 28, 2019.
*Implementes the intersection portion infront of the lanes
*/
#include "Intersection.h"
#include "VehicleBase.h"
#include <stdlib.h>
#include <iostream>

Intersection::Intersection(){
    for (int i = 0; i < 4; i++){
        Section section(false, true, NULL);
        sections.push_back(section);
        dontOverWrite.push_back(false);
        lastSection.push_back(0);
    }
}


void Intersection::advance(LightColor ns){ 

    if (ns == LightColor::green || ns == LightColor::yellow){
        sections[1].setPtr(sections[3].getPtr());
        sections[2].setPtr(sections[0].getPtr());
        
    }
    else if (ns == LightColor::red){
        sections[3].setPtr(sections[2].getPtr());
        sections[0].setPtr(sections[1].getPtr());
        
        
    }
    
    if (sections[3].getOccupied() && (sections[3].getPtr()->getVehicleOriginalDirection() == Direction::north) ){ // for left turn do or direction and check if occupied 
        dontOverWrite[1] = true;
    }
    else{
        dontOverWrite[1] = false;
        //cout << "here: 1" << endl;
    }

    if (sections[0].getOccupied() && sections[0].getPtr()->getVehicleOriginalDirection() == Direction::south)
        dontOverWrite[2] = true;
    else
        dontOverWrite[2] = false;
    
    if (sections[2].getOccupied() && sections[2].getPtr()->getVehicleOriginalDirection() == Direction::east){
        dontOverWrite[3] = true;
    }
    else{
        dontOverWrite[3] = false;
    }

    if (sections[1].getOccupied() && sections[1].getPtr()->getVehicleOriginalDirection() == Direction::west)
        dontOverWrite[0] = true;
    else
        dontOverWrite[0] = false;

}


void Intersection::arrival(VehicleBase* veh, int quadrant){
    sections[quadrant].setPtr(veh);
}


bool Intersection::isLeaving(int quadrant, Direction dir){
     return (sections[quadrant].getOccupied() && (sections[quadrant].getPtr()->getVehicleOriginalDirection() == dir));
}


vector<bool> Intersection::getDontOverWrite(){
    return dontOverWrite;
}


vector<int> Intersection::getLastSection(){
    return lastSection;
}


vector<VehicleBase*> Intersection::getVehicles(){
    vector<VehicleBase*> vs;
    //cout << "Intersection" << endl;
    for (int i = 0; i < (int)sections.size(); i++){
        vs.push_back(sections[i].getPtr());
      //  cout << sections[i].getPtr() << endl;
    }

    return vs;
}
