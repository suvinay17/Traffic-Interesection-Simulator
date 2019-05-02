#include "Roadways.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

/* Writted by Ting, Suvinay, Allie. This program is passed the name of a 
 * correctly formatted input file with the required parameters. It reads 
 * that files and simulates a traffic intersection passed on the parameters 
 * from the input file.
 */

int main(int argc, char* argv[]){
    ifstream inputFile; // input-file stream variable for reading
    
    // check for correct number of command-line arguments, or else print error message and terminate program
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

    vector<double> readData; // data from input file

    string token;
    string dummy;
    
    // parse input file, stream through dummy first to get actual token of data 
    while (inputFile.good()){
        inputFile >> dummy >> token;

        readData.push_back(stod(token));
        
        // once we reach end of file, break
        if (inputFile.eof()) 
            break;
        else if (inputFile.fail()){
            cerr << "Error reading file" << endl;
            return 1;
        }
    }
     
    // always remember to close your stream!
    inputFile.close();
    
    // create container class for intersection and lanes with input parameters from read file
    Roadways roadways(readData);

    int t = 0;
    int time = (int)readData[0]; // max simulation time from read in file 
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
            cin.get(dummyChar); // read in dummy key press
            roadways.advance(t);
        }
        else{
            this_thread::sleep_for(std::chrono::milliseconds(200)); // delay by 200 milliseconds
            roadways.advance(t);
        }
        t++;
    }
    
    roadways.clear(); // clean up dynamically allocated data

    return 0;
}
