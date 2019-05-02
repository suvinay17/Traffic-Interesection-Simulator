#include "Roadways.h"
#include <iostream>
#include <chrono>
#include <random>

/* This program serves as the container class for the intersection
 * and lanes. Thus it is the main class in hte simulation and is constructed
 * with a vector of parameters. Once it is constructed, you should advance the 
 * simulation by sending it a time and at the end clear the Roadways of vehicles.
 */

// constructor taking in a vector of parameters and initializing the traffic lights
// and the animator
Roadways::Roadways(vector<double> inParams) : inputParameters(inParams), myAnimator((int)inParams[1]), 
    northSouthLight((int)inParams[2], (int)inParams[4] + (int)inParams[5], (int)inParams[3], LightColor::red), 
    eastWestLight((int)inParams[4], (int)inParams[2] + (int)inParams[3], (int)inParams[5], LightColor::green){
    
        Direction orientations[4] = {Direction::north, Direction::south, Direction::east, Direction::west}; 

        for (int i = 0; i < 8; i++){
            Lane lane((int)inputParameters[1], orientations[i/2]);
            myLanes.push_back(lane);
        }

        for (int j = 0; j < (2 * (int)(inputParameters[1]) + 2); j++){
            northBound.push_back(nullptr);
            southBound.push_back(nullptr);
            westBound.push_back(nullptr);
            eastBound.push_back(nullptr);
        }

        lights.push_back(northSouthLight);
        lights.push_back(eastWestLight);
        
        bounds.push_back(northBound);
        bounds.push_back(southBound);
        bounds.push_back(eastBound);
        bounds.push_back(westBound);
}

// advances the simulation by advancing all the lanes and having one random arrival
// in one of the lanes
void Roadways::advance(int t){

    // obtain a seed from the system clock:
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 generator(seed);
    
    // use a uniform (0, 1) distribution
    uniform_real_distribution<double> dist(0.0, 1.0);

    // three random numbers for arrival lane, vehicle type, and direction
    // of destination
    double rand = dist(generator);
    double rand2 = dist(generator);
    double rand3 = dist(generator);
 
    // Setting up lights to be drawn
    myAnimator.setLightNorthSouth(lights[0].getStatus());
    myAnimator.setLightEastWest(lights[1].getStatus());
    

    // Setting up vehicles to be drawn
    myAnimator.setVehiclesNorthbound(bounds[0]);
    myAnimator.setVehiclesSouthbound(bounds[1]);
    myAnimator.setVehiclesEastbound(bounds[2]);
    myAnimator.setVehiclesWestbound(bounds[3]);
    myAnimator.draw(t);

    // advance intersection
    myIntersection.advance(lights[0].getStatus());
    
    // arrivals into intersection
    for (int i = 0; i < 4; i++){
        if (!myIntersection.getDontOverWrite()[i]) 
            myIntersection.arrival(nullptr, i);
    }
    
    // loop through each cardinal direction
    for (int j = 0; j < 8; j += 2){
        
        int k, q, pick = 0; // k corresponds to the first section of the 
                            // intersection that the vehicle enters, 
                            // q is the second one as it leaves, 
                            // pick is the choice of going straight 
                            // or turning right
        
        bool h = false; // initially no spawn
        Direction d[2];
        VehicleType type;

        if (j == 0){
            // random part of selecting vehicle arrival
            if (rand < inputParameters[6]){
                h = true; 

                if (rand2 < inputParameters[10]){
                    type = VehicleType::car;

                    if (rand3 < inputParameters[12])
                        pick = 1;
                    else
                        pick = 0;
                }
                else if (rand2 > inputParameters[10] && rand2 < inputParameters[10] + inputParameters[11]){
                    type = VehicleType::suv;

                    if (rand3 < inputParameters[14])
                        pick = 1;
                    else 
                        pick = 0;
                }
                else{
                    type = VehicleType::truck;

                    if (rand3 < inputParameters[16])
                        pick = 1;
                    else 
                        pick = 0;
                }
            }
                        
            d[0] = Direction::north; // northbound, go straight 
            d[1] = Direction::east;  // eastbound, turn right
            
            k = 3;
            q = 1;
        }
        else if (j == 2){
            // random part of selecting vehicle arrival
            if (rand < inputParameters[7] + inputParameters[6] && rand > inputParameters[6]){
                h = true; 

                if (rand2 < inputParameters[10]){
                    type = VehicleType::car;

                    if (rand3 < inputParameters[12])
                        pick = 1;
                    else
                        pick = 0;
                }
                else if (rand2 > inputParameters[10] && rand2 < inputParameters[10] + inputParameters[11]){
                    type = VehicleType::suv;

                    if (rand3 < inputParameters[14])
                        pick = 1;
                    else 
                        pick = 0;
                }
                else{
                    type = VehicleType::truck;

                    if (rand3 < inputParameters[16])
                        pick = 1;
                    else 
                        pick = 0;
                }
            }

            d[0] = Direction::south; // southbound, go straight
            d[1] = Direction::west;  // westbound, turn right

            k = 0;
            q = 2;
        }
        else if (j == 4){ 
            // random part of selecting vehicle arrival
            if (rand < inputParameters[8] + inputParameters[7] + inputParameters[6] && (rand > inputParameters[6] + inputParameters[7])){
                h = true; 

                if (rand2 < inputParameters[10]){
                    type = VehicleType::car;

                    if (rand3 < inputParameters[12])
                        pick = 1;
                    else
                        pick = 0;
                }
                else if (rand2 > inputParameters[10] && rand2 < inputParameters[10] + inputParameters[11]){
                    type = VehicleType::suv;

                    if (rand3 < inputParameters[14])
                        pick = 1;
                    else 
                        pick = 0;
                }
                else{
                    type = VehicleType::truck;

                    if (rand3 < inputParameters[16])
                        pick = 1;
                    else 
                        pick = 0;
                }
            }
            
            d[0] = Direction::east; // eastbound, go straight
            d[1] = Direction::south; // southbound, turn right
            
            k = 2;
            q = 3;
        }
        else{
            // random part of selecting vehicle arrival
            if (rand > inputParameters[6] + inputParameters[7] + inputParameters[8]){
                h = true; 

                if (rand2 < inputParameters[10]){
                    type = VehicleType::car;

                    if (rand3 < inputParameters[12])
                        pick = 1;
                    else
                        pick = 0;
                }
                else if (rand2 > inputParameters[10] && rand2 < inputParameters[10] + inputParameters[11]){
                    type = VehicleType::suv;

                    if (rand3 < inputParameters[14])
                        pick = 1;
                    else 
                        pick = 0;
                }
                else{
                    type = VehicleType::truck;

                    if (rand3 < inputParameters[16])
                        pick = 1;
                    else 
                        pick = 0;
                }
            }

            d[0] = Direction::west;  // westbound, go straight 
            d[1] = Direction::north; // northbound, turn right
            
            k = 1;
            q = 0;
        }

        int left = 0;
        int index = (int)inputParameters[1] - 1;

        // detect how many section of the vehicle pointer are left before the intersection
        VehicleBase* stopped = myLanes[j].getVehicles()[index]; 
        while (index > 0 && myLanes[j].getVehicles()[index] != nullptr && myLanes[j].getVehicles()[index] == stopped){
            left++;
            index--;
        }

        // advance into intersection
        if (myLanes[j].beforeIntersection() && lights[j/4].getStatus() == LightColor::green &&
                (lights[j/4].getCurrentTime() > myLanes[j].getVehicles()[inputParameters[1] - 1]->getVehicleSize() + 2 || lights[j/4].getCurrentTime() > left + 2 )){
            myIntersection.arrival(myLanes[j].getVehicles().back(), k);
        }

        // advance preceding lane
        if (lights[j/4].getStatus() == LightColor::green){
            if (myLanes[j].getVehicles()[inputParameters[1] - 1] != nullptr &&
                    (lights[j/4].getCurrentTime() > myLanes[j].getVehicles()[inputParameters[1] - 1]->getVehicleSize() + 2 || lights[j/4].getCurrentTime() > left +2  ))
                myLanes[j].advance();
            else
                myLanes[j].advanceRed();
        }
        else
            myLanes[j].advanceRed();

        VehicleBase* arrivee;

        if (h)
            arrivee = new VehicleBase(type, d[pick]);


        // arrival in preceding lane 
        myLanes[j].carArrival(d[pick], h, arrivee);

        // advance and arrival in following lane 
        myLanes[j + 1].advance();

        if (myLanes[j + 1].getContinuedArrival()){
            myLanes[j + 1].carArrival(myLanes[j + 1].getContinuedArrivee());
            myLanes[j + 1].setContinuedArrival(false);
        }
        else
            myLanes[j + 1].carArrival(nullptr);

        // leaving intersection
        if (myIntersection.isLeaving(q, d[0])){
            myLanes[j + 1].setContinuedArrival(true);  
            myLanes[j + 1].setContinuedArrivee(myIntersection.getVehicles()[q]); 

        }

        // Copying from Lanes and intersection into the vectors that are drawn

        for (int i = 0; i < (int)inputParameters[1]; i++)
            bounds[j/2][i] = myLanes[j].getVehicles()[i]; 
        
        for (int i = (int)inputParameters[1]; i < (int)inputParameters[1] + 2; i++){
            bounds[j/2][i] = myIntersection.getVehicles()[k];
        
            k = q;
        }
        
        for (int i = (int)inputParameters[1] + 2; i < (int)inputParameters[1] + 2 + (int)inputParameters[1]; i++)
            bounds[j/2][i] = myLanes[j + 1].getVehicles()[i - (int)inputParameters[1] - 2];
    }

    // check again in north and south bound lanes for vehicles leaving the intersection
    for (int j = 0; j < 4; j += 2){
        int q ;
        Direction d[2];
        
        if (j == 0){
            d[1] = Direction::east;
            d[0] = Direction::north;
            q = 1;
        }
        else if (j == 2){
            d[1] = Direction::west;
            d[0] = Direction::south;
            q = 2;
        }

        if (myIntersection.isLeaving(q, d[0])){
            myLanes[j + 1].setContinuedArrival(true);  
            myLanes[j + 1].setContinuedArrivee(myIntersection.getVehicles()[q]); 

        }

    }
        
    // Updating lights
    lights[0].updateLight();
    lights[1].updateLight();
}

// deallocate dynamic data pointers
void Roadways::clear(){
    for (int i = 0; i < 8; i++){
        myLanes[i].clear();
    }
}

