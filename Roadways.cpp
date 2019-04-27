#include "Roadways.h"
#include <iostream>

Roadways::Roadways(int numSections) : myAnimator(numSections), numberOfSections(numSections),
    northSouthLight(12, 15, 3, LightColor::red), eastWestLight(12, 15 ,3, LightColor::green){
    Direction orientations[4] = {Direction::north, Direction::south, Direction::east, Direction::west}; 


    for (int i = 0; i < 8; i++){
        Lane lane(numSections, orientations[i/2]);
        myLanes.push_back(lane);
    }


    for (int j = 0; j < (2 * (numSections) + 2); j++){
        northBound.push_back(NULL);
        southBound.push_back(NULL);
        westBound.push_back(NULL);
        eastBound.push_back(NULL);
    }

    lights.push_back(northSouthLight);
    lights.push_back(eastWestLight);
    
    bounds.push_back(northBound);
    bounds.push_back(southBound);
    bounds.push_back(eastBound);
    bounds.push_back(westBound);

    /*vector<VehicleBase*> northSouth;
    
    northSouth.push_back(NULL);    
    northSouth.push_back(NULL);    
    northSouth.push_back(NULL);    
    northSouth.push_back(NULL);  
    northSouth.push_back(NULL);    
    northSouth.push_back(NULL);    
    northSouth.push_back(NULL);    
    northSouth.push_back(NULL);     

    myAnimator.setVehiclesNorthbound(northSouth);
    myAnimator.setVehiclesSouthbound(northSouth);
    myAnimator.setVehiclesWestbound(northSouth);
    myAnimator.setVehiclesEastbound(northSouth);
    myAnimator.setLightNorthSouth(LightColor::red);
    myAnimator.setLightEastWest(LightColor::green);*/

    // myAnimator.draw(0);
}

void Roadways::advance(int t){
    
    /*if (t == 12)
        eastWestLight.setStatus(LightColor::green);
    */

    // Setting up lights to be drawn
    myAnimator.setLightNorthSouth(lights[0].getStatus());
    myAnimator.setLightEastWest(lights[1].getStatus());
    

    // Setting up vehicles to be drawn
    myAnimator.setVehiclesNorthbound(bounds[0]);
    myAnimator.setVehiclesSouthbound(bounds[1]);
    myAnimator.setVehiclesEastbound(bounds[2]);
    myAnimator.setVehiclesWestbound(bounds[3]);
    myAnimator.draw(t);

    cout << "intersection: " << endl;
    for (int k = 0; k < 4; k++){
        cout << k << ": " << myIntersection.getVehicles()[k] << endl;
        if (myIntersection.getVehicles()[k] != nullptr)
            cout << " Dir: " << (int)myIntersection.getVehicles()[k]->getVehicleOriginalDirection() <<endl; 
    }


      
    /*cout << "Eastbound: " << endl;
    for (int i = 0; i < bounds[2].size(); i++){
       cout << bounds[2][i] << endl;
    } */

     // advance intersection
    myIntersection.advance(lights[0].getStatus());

    for (int i = 0; i < 4; i++){
        if (!myIntersection.getDontOverWrite()[i])// || myIntersection.getLastSection()[q] < 0)
            myIntersection.arrival(nullptr, i);
    }

       /* // advance into intersection
        if (myLanes[4].beforeIntersection() && eastWestLight.getStatus() == LightColor::green){
            myIntersection.arrival(myLanes[4].getVehicles().back());
            cout << "here" << endl;
        }
        else
            myIntersection.arrival(nullptr);
        // advance preceding lane
        if (eastWestLight.getStatus() == LightColor::green)
            myLanes[4].advance();
        else
            myLanes[4].advanceRed();
        
        // arrival in preceding lane 
        spawn();
        
        // advance and arrival in following lane 
        myLanes[5].advance();

        if (myLanes[5].getContinuedArrival()){
            myLanes[5].carArrival(myLanes[5].getContinuedArrivee());
            myLanes[5].setContinuedArrival(false);
        }
        else
            myLanes[5].carArrival(nullptr);

        // leaving intersection
        if (myIntersection.isLeaving()){
            myLanes[5].setContinuedArrival(true);  
            myLanes[5].setContinuedArrivee(myIntersection.getVehicles()[3]);  
        }

        // Copying from Lanes and intersection into the vectors that are drawn

        for (int i = 0; i < myLanes[4].getVehicles().size(); i++)
            eastBound[i] = myLanes[4].getVehicles()[i];

        int k = 2;
        
        for (int i = numberOfSections; i < numberOfSections + 2; i++){
            eastBound[i] = myIntersection.getVehicles()[k];
            k++;
        }
        
        for (int i = numberOfSections + 2; i < numberOfSections + 2 + numberOfSections; i++)
            eastBound[i] = myLanes[5].getVehicles()[i - numberOfSections - 2]; */

    for (int j = 0; j < 8; j += 2){
        
        int k;
        Direction d;
        
        if (j == 0){
            d = Direction::north; // northbound 
            k = 3;
        }
        else if (j == 2){
            d = Direction::south;// southbound
            k = 0;
        }
        else if (j == 4){ // eastbound
            k = 2;
            d = Direction::east;
        }
        else{
            d = Direction::west;// westbound
            k = 1;
        }

        int q;
        if (j == 0) // northbound 
            q = 1;
        else if (j == 2) // southbound
            q = 2;
        else if (j == 4) // eastbound
            q = 3;
        else  // westbound
            q = 0;

        /*cout << "Last Section" << endl;
        cout << k << ": " << myIntersection.getLastSection()[k] << endl;*/
        // advance into intersection
        if (myLanes[j].beforeIntersection() && lights[j/4].getStatus() == LightColor::green){
            myIntersection.arrival(myLanes[j].getVehicles().back(), k);
            //cout << "here" << endl;
        }

        // advance preceding lane
        if (lights[j/4].getStatus() == LightColor::green)
            myLanes[j].advance();
        else
            myLanes[j].advanceRed();

        bool h;

        if (t == 0)// || t == 5)
            h = true;
        else
            h = false;

        // arrival in preceding lane 
        myLanes[j].carArrival(d, h);
        
        // advance and arrival in following lane 
        myLanes[j + 1].advance();

        if (myLanes[j + 1].getContinuedArrival()){
            myLanes[j + 1].carArrival(myLanes[j + 1].getContinuedArrivee());
            myLanes[j + 1].setContinuedArrival(false);
        }
        else
            myLanes[j + 1].carArrival(nullptr);

        

        // leaving intersection
        if (myIntersection.isLeaving(q, d)){
            myLanes[j + 1].setContinuedArrival(true);  
            myLanes[j + 1].setContinuedArrivee(myIntersection.getVehicles()[q]);  
        }

        // Copying from Lanes and intersection into the vectors that are drawn

        for (int i = 0; i < numberOfSections; i++)
            bounds[j/2][i] = myLanes[j].getVehicles()[i]; //  and intersection 

        
        for (int i = numberOfSections; i < numberOfSections + 2; i++){
            bounds[j/2][i] = myIntersection.getVehicles()[k];
        
            k = q;
        }
        
        for (int i = numberOfSections + 2; i < numberOfSections + 2 + numberOfSections; i++)
            bounds[j/2][i] = myLanes[j + 1].getVehicles()[i - numberOfSections - 2];
    }
        
    // Updating lights

    lights[0].updateLight();
    lights[1].updateLight();
}

