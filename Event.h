//
// Created by Ahmet Emir Kocaaga on 10.11.2018.
//

#ifndef PROJECT2_EVENT_H
#define PROJECT2_EVENT_H
#include <queue>
#include "Passenger.h"
#include <vector>

using namespace std;

class Event {

public:

    int type;
    int exeTime;
    int lugFinTime;
    Passenger* pass;

    Event();

    Event(int type, int exeTime, int lugFin, Passenger* p);


};
struct compareEvents {

    bool operator()(Event* a, Event* b) {
        if(a->exeTime == b->exeTime && a->type == 0 && b->type == 0){
            return a->pass->arriveTime > b->pass->arriveTime;
        }
        if(a->exeTime == b->exeTime && a->type == 1 && b->type == 1){
            return a->pass->arriveTime > b->pass->arriveTime;
        }
        if(a->exeTime == b->exeTime && a->type == 2 && b->type == 2){
            return a->pass->arriveTime > b->pass->arriveTime;
        }
        if(a->exeTime == b->exeTime){
            return a->type < b->type;
        }
        else{
            return a->exeTime > b->exeTime;
        }
    }
};

struct compareEventsFly {

    bool operator()(Event* a, Event* b){
        if(a->exeTime == b->exeTime && a->type == b->type){
            return a->pass->arriveTime > b->pass->arriveTime;
        }
        if(a->exeTime == b->exeTime){
            return a->type < b->type;
        }
        else{
            return a->exeTime > b->exeTime;
        }
    }


};

struct compareFirstFly {

    bool operator()(Event* a, Event* b){



        if(a->pass->boardingTime == b->pass->boardingTime){
            return a->pass->arriveTime > b->pass->arriveTime;
        }

        return a->pass->boardingTime > b->pass->boardingTime;

    }


};


#endif //PROJECT2_EVENT_H
