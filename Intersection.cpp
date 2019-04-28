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
   /* if (sections[2].getOccupied() && sections[2].getPtr()->getVehicleOriginalDirection() == Direction::east){
        sections[3].setPtr(sections[2].getPtr());
        dontOverWrite[3] = true;
        
        if (lastSection[2] == 0)
            lastSection[2] = sections[3].getPtr()->getVehicleSize();
        else
            lastSection[2]--;
    }
    else{
        dontOverWrite[3] = false;
        sections[3].setPtr(sections[2].getPtr());

    }
    if (sections[3].getOccupied() && sections[3].getPtr()->getVehicleOriginalDirection() == Direction::north){
        sections[1].setPtr(sections[3].getPtr());
        dontOverWrite[1] = true;
        
        if (lastSection[3] == 0)
            lastSection[3] = sections[1].getPtr()->getVehicleSize();
        else
            lastSection[3]--;
    }
    else{
        dontOverWrite[1] = false;
       // sections[1].setPtr(sections[3].getPtr());
    }
    
    if (sections[0].getOccupied() && sections[0].getPtr()->getVehicleOriginalDirection() == Direction::south){
        sections[2].setPtr(sections[0].getPtr());
        dontOverWrite[2] = true;
        
        if (lastSection[0] == 0)
            lastSection[0] = sections[2].getPtr()->getVehicleSize();
        else
            lastSection[0]--;
    }
    else{
        dontOverWrite[2] = false;
       // sections[2].setPtr(sections[0].getPtr());
    }

    if (sections[1].getOccupied() && sections[1].getPtr()->getVehicleOriginalDirection() == Direction::west){
        sections[0].setPtr(sections[1].getPtr());
        dontOverWrite[0] = true; 
        
        if (lastSection[1] == 0)
            lastSection[1] = sections[0].getPtr()->getVehicleSize();
        else
            lastSection[1]--;
    }
    else{
        dontOverWrite[0] = false;
        sections[0].setPtr(sections[1].getPtr());
    }*/

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
    for (int i = 0; i < sections.size(); i++){
        vs.push_back(sections[i].getPtr());
      //  cout << sections[i].getPtr() << endl;
    }

    return vs;
}
