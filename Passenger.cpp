//
// Created by Ahmet Emir Kocaaga on 9.11.2018.
//

#include "Passenger.h"

Passenger::Passenger() {

    this->arriveTime = 0;
    this->boardingTime = 0;
    this->lugFinish = 0;
    this->lugStart = 0;
    this->secStart = 0;
    this->lugTime = 0;
    this->secTime = 0;
    this->lug = false;
    this->vip = false;

}

Passenger::Passenger(int arrive, int boarding, int lugS, int lugFin, int secS, int lug, int sec, char ifVip, char ifLug) {

    this->arriveTime = arrive;
    this->boardingTime = boarding;
    this->lugFinish = lugFin;
    this->lugTime = lug;
    this->secTime = sec;
    this->vip = ifVip == 'V';
    this->lug = ifLug == 'N';

}

bool Passenger:: operator<(Passenger other){

    return this->arriveTime < other.arriveTime;

}

