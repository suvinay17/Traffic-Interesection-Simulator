#include "Roadways.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

int main(int argc, char* argv[]){
    ifstream inputFile; // input-file stream variable for reading
    
    //check for correct number of command-line arguments, or else print error message and terminate program
    if (argc != 3){
        cerr << "Usage: " << argv[0] << " [input text filename] " << "[boolean value for pause stepability]" << endl;
        return 0;
    }

    // open file and check that it is successfully opened
    inputFile.open(argv[1]);
    if (!inputFile.is_open()){
        cerr << "Error: Unable to open file " << argv[1] << endl;
        return 1;
    }

    int i = 0;
    
    vector<double> readData;

    string token;
    string dummy;

    while (inputFile.good()){
        inputFile >> dummy >> token;

        readData.push_back(stod(token));
        
        if (inputFile.eof())
            break;
        else if (inputFile.fail()){
            cerr << "Error reading file" << endl;
            return 1;
        }

        i++;
    }

    inputFile.close();

    Roadways roadways(readData);

    int t = 0;
    int time = 10; //(int)readData[0];
    bool stepActivated;
    char dummyChar;
    
    string arg2 = argv[2];
    
    if (arg2.compare("true") == 0)
        stepActivated = true;
    else
        stepActivated = false;

    while (t <= time){
        if (t == 0)
            cout << "Press enter to start:";
        if (stepActivated){
            cin.get(dummyChar);
            roadways.advance(t);
        }
        else{
            this_thread::sleep_for(std::chrono::milliseconds(200)); // delay by 200 milliseconds
            roadways.advance(t);
        }
        t++;
    }
    
    roadways.clear();

    return 0;
}
