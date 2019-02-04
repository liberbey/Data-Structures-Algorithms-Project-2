//
// Created by Ahmet Emir Kocaaga on 9.11.2018.
//

#ifndef PROJECT2_SIMULATION_H
#define PROJECT2_SIMULATION_H

#include "Passenger.h"
#include <iostream>
#include <queue>
#include <vector>
#include "Event.h"
#include <sstream>
#include <fstream>
#include <iterator>

using namespace std;


class Simulation {

public:

    Simulation();

    Simulation(vector<Passenger*> passengers, int lugCounter, int secCounter);

    string makeSim(vector<Passenger*> passengers, int lugCounter, int secCounter, ofstream &myFile);

    string makeSim1(vector<Passenger*> passengers, int lugCounter, int secCounter, ofstream &myFile);

    string makeSim2(vector<Passenger*> passengers, int lugCounter, int secCounter, ofstream &myFile);

    string makeSim3(vector<Passenger*> passengers, int lugCounter, int secCounter, ofstream &myFile);

    string makeSim4(vector<Passenger*> passengers, int lugCounter, int secCounter, ofstream &myFile);

    string makeSim5(vector<Passenger*> passengers, int lugCounter, int secCounter, ofstream &myFile);

    string makeSim6(vector<Passenger*> passengers, int lugCounter, int secCounter, ofstream &myFile);

    string makeSim7(vector<Passenger*> passengers, int lugCounter, int secCounter, ofstream &myFile);

};


#endif //PROJECT2_SIMULATION_H
