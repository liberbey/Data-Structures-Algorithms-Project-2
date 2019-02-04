//
// Created by Ahmet Emir Kocaaga on 9.11.2018.
//

#ifndef PROJECT2_PASSENGER_H
#define PROJECT2_PASSENGER_H

#include <iostream>

using namespace std;

class Passenger {

public:

    int arriveTime;
    int boardingTime;
    int lugStart;
    int lugFinish;
    int secStart;
    int lugTime;
    int secTime;
    bool vip;
    bool lug;

    Passenger();

    Passenger(int arrive, int boarding, int lugS, int lugFin, int secS, int lug, int sec, char ifVip, char ifLug);

    bool operator<(Passenger other);









};
struct compareArrival {

    bool operator()(Passenger* a, Passenger* b) {
        return a->arriveTime > b->arriveTime;
    }
};


#endif //PROJECT2_PASSENGER_H
