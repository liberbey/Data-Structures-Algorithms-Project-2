//
// Created by Ahmet Emir Kocaaga on 10.11.2018.
//

#include "Event.h"

Event::Event() {

    this->exeTime = 0;
    this->lugFinTime = 0;
    this->pass = nullptr;
    this->type = 0;

}

Event::Event(int type, int exeTime, int lugFin, Passenger *p) {

    this->type = type;
    this->lugFinTime = 0;
    this->pass = p;
    this->exeTime = exeTime;

}