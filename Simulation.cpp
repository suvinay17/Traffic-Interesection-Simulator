#include "Roadways.h"
//#include "ParameterParser.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]){
    //ifstream inputFile; // input-file stream variable for reading
    
    // check for correct number of command-line arguments, or else print error message and terminate program
    /* if (argc != 2){
        cerr << "Usage: " << argv[0] << " [input text filename]" << endl;
        return 0;
    }*/

    // open file and check that it is successfully opened
    //inputFile.open(argv[1]);
    /*if (!inputFile.is_open()){
        cerr << "Error: Unable to open file " << argv[1] << endl;
        return 1;
    }

    int time;
    int i = 0;
    
    vector<int> readData;

    string token;
    string dummy;

    while (inputFile.good()){
        inputFile >> dummy >> token;

        readData[i] = stoi(token);
        
        if (inputFile.eof())
            break;
        else if (inputFile.fail()){
            cerr << "Error reading file" << endl;
            return 1;
        }

        i++;
    }

    inputFile.close();*/

    //ParameterParser parser(argv[1]);

    //parser.getSimTime();

    Roadways roadways(8);

    int t = 0;
    int time = 40;
    char dummyChar;
    while (t <= time){
        if (t == 0)
            cout << "Press enter to start:";
        cin.get(dummyChar);
        roadways.advance(t);
        t++;
    }
    
    //roadways.clear();

    return 0;
}
