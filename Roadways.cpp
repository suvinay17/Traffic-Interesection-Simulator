#include "Roadways.h"
#include <iostream>
#include <chrono>
#include <random>


Roadways::Roadways(vector<double> inParams) : inputParameters(inParams), myAnimator((int)inParams[1]), 
    northSouthLight((int)inParams[2], (int)inParams[4] + (int)inParams[5], (int)inParams[3], LightColor::red), 
    eastWestLight((int)inParams[4], (int)inParams[2] + (int)inParams[3], (int)inParams[5], LightColor::green){
    Direction orientations[4] = {Direction::north, Direction::south, Direction::east, Direction::west}; 


    for (int i = 0; i < 8; i++){
        Lane lane((int)inputParameters[1], orientations[i/2]);
        myLanes.push_back(lane);
    }


    for (int j = 0; j < (2 * (int)(inputParameters[1]) + 2); j++){
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

}

void Roadways::advance(int t){

    // obtain a seed from the system clock:
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 generator(seed);

    uniform_real_distribution<double> dist(0.0, 1.0);

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

    
    /*cout << "intersection: " << endl;
    for (int k = 0; k < 4; k++){
        cout << k << ": " << myIntersection.getVehicles()[k] << endl;
        if (myIntersection.getVehicles()[k] != nullptr)
            cout << " Dir: " << (int)myIntersection.getVehicles()[k]->getVehicleOriginalDirection() <<endl; 
    }*/


      
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

    for (int j = 0; j < 8; j += 2){
        
        int k, q, pick = 0;
        bool h = false;
        Direction d[2];
        VehicleType type;

        if (j == 0){
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
                        
            d[1] = Direction::east;
            d[0] = Direction::north; // northbound 
            k = 3;
            q = 1;
        }
        else if (j == 2){
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

            d[1] = Direction::west;// southbound
            d[0] = Direction::south;

            k = 0;
            q = 2;
        }
        else if (j == 4){ // eastbound
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
            
            k = 2;
            d[0] = Direction::east;
            d[1] = Direction::south;
            q = 3;
        }
        else{
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
            d[0] = Direction::west;// westbound
            d[1] = Direction::north;// westbound
            pick = 1;
            k = 1;
            q = 0;
        }

        /*cout << "Last Section" << endl;
        cout << k << ": " << myIntersection.getLastSection()[k] << endl;*/
        int left = 0;
        int index = (int)inputParameters[1] - 1;
        while (index > 1 && myLanes[j].getVehicles()[index] != nullptr && (myLanes[j].getVehicles()[index] == myLanes[j].getVehicles()[index - 1] || 
                myLanes[j].getVehicles()[(int)inputParameters[1] - 2] == nullptr)){
            left++;
            index--;
        }

        //cout << "LightTime " << lights[j/4].getCurrentTime() << endl;
        //cout << "left " << left << endl;


        // advance into intersection
        if (myLanes[j].beforeIntersection() && lights[j/4].getStatus() == LightColor::green &&
                (lights[j/4].getCurrentTime() > myLanes[j].getVehicles()[inputParameters[1] - 1]->getVehicleSize() + 2 || lights[j/4].getCurrentTime() > left )){
            myIntersection.arrival(myLanes[j].getVehicles().back(), k);
        }

        // advance preceding lane
        if (lights[j/4].getStatus() == LightColor::green){
            if (myLanes[j].getVehicles()[inputParameters[1] - 1] != nullptr &&
                    (lights[j/4].getCurrentTime() > myLanes[j].getVehicles()[inputParameters[1] - 1]->getVehicleSize() + 2 || lights[j/4].getCurrentTime() > left ))
                myLanes[j].advance();
            else
                myLanes[j].advanceRed();
        }
        else
            myLanes[j].advanceRed();

        
        
        VehicleBase* arrive = new VehicleBase(type, d[pick]);

        //if (t == 0 || t == 5)
          //  h = true;
        //else
        //    h = false;

        // arrival in preceding lane 
        myLanes[j].carArrival(d[pick], h, arrive);
        
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

            //cout << "j: " << j << endl;
            //cout << "q: " << q << endl;
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

    for (int j = 0; j < 4; j += 2){
        int k, q, pick = 0;
        Direction d[2];
        
        if (j == 0){
            d[1] = Direction::east;
            d[0] = Direction::north; // northbound 
            k = 3;
            q = 1;
        }
        else if (j == 2){
            d[1] = Direction::west;// southbound
            d[0] = Direction::south;
            q = 2;
            k = 0;
        }

        if (myIntersection.isLeaving(q, d[0])){
            myLanes[j + 1].setContinuedArrival(true);  
            myLanes[j + 1].setContinuedArrivee(myIntersection.getVehicles()[q]); 

            //cout << "j: " << j << endl;
            //cout << "q: " << q << endl;
        }

    }
        
    // Updating lights

    lights[0].updateLight();
    lights[1].updateLight();
}

