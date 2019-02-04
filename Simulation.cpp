//
// Created by Ahmet Emir Kocaaga on 9.11.2018.
//

#include "Simulation.h"
#include "Passenger.h"
#include <array>
#include <string>


Simulation::Simulation(){}

Simulation::Simulation(vector<Passenger*> passengers, int lugCounter, int secCounter) {}


string Simulation::makeSim(vector<Passenger*> passengers, int lugCounter, int secCounter, ofstream &file){

    priority_queue<Event*, vector<Event*>, compareEvents> eventQ;
    queue<Event*> lugProcessQ;
    queue<Event*> secProcessQ;
    int lugProcess = lugCounter;
    int secProcess = secCounter;
    int clock = 0;
    int totalTime = 0;
    int missedFlight = 0;
    int numOfPass = (int)passengers.size();

    for(int i = 0; i < passengers.size(); i++){

        Event *e = new Event;
        e->type = 0;
        e->lugFinTime = 0;
        e->exeTime = passengers[i]->arriveTime;
        e->pass = passengers[i];
        eventQ.push(e);

    }


    while(eventQ.size() !=0){


        Event *e1 = eventQ.top();
        clock = e1->exeTime;
        eventQ.pop();
        if(e1->type == 0){

            if(lugProcess > 0){
                e1->exeTime = clock + e1->pass->lugTime;
                e1->type = 1;
                lugProcess--;
                eventQ.push(e1);
            }
            else{
                //LUGcounterlar dolu
                lugProcessQ.push(e1);
            }
        }
        else if(e1->type == 1){

            lugProcess++;
            if (!lugProcessQ.empty()) {
                Event *temp = lugProcessQ.front();
                lugProcessQ.pop();
                temp->exeTime = clock + temp->pass->lugTime;
                temp->type = 1;
                eventQ.push(temp);
                lugProcess--;
            }

            if(secProcess > 0) {

                secProcess--;
                e1->exeTime = clock + e1->pass->secTime;
                e1->type = 2;
                eventQ.push(e1);
            }

            else{
                //SECcounterlar dolu
                secProcessQ.push(e1);
            }

        }
        else {
            secProcess++;
            if(!secProcessQ.empty()) {
                Event *temp = secProcessQ.front();
                temp->type = 2;
                temp->exeTime = clock + temp->pass->secTime;
                eventQ.push(temp);
                secProcessQ.pop();
                secProcess--;
            }
            totalTime += (clock - e1->pass->arriveTime);
            if(clock > e1->pass->boardingTime){
                missedFlight++;
            }

        }


    }


    double Average = (double)totalTime/(double)numOfPass;

    cout << Average << " " << missedFlight << endl;

    file << Average << " " << missedFlight << endl;


    string s = to_string(Average);
    string s1 = to_string(missedFlight);
    return s + " " + s1;

}

string Simulation::makeSim1(vector<Passenger *> passengers, int lugCounter, int secCounter, ofstream &file) {

    priority_queue<Event*, vector<Event*>, compareEventsFly> eventQ;
    priority_queue<Event*, vector<Event*>, compareFirstFly> lugProcessQ;
    priority_queue<Event*, vector<Event*>, compareFirstFly> secProcessQ;
    int lugProcess = lugCounter;
    int secProcess = secCounter;
    int clock = 0;
    int totalTime = 0;
    int missedFlight = 0;
    int numOfPass = (int)passengers.size();

    for(int i = 0; i < passengers.size(); i++){

        Event *e = new Event;
        e->type = 0;
        e->lugFinTime = 0;
        e->exeTime = passengers[i]->arriveTime;
        e->pass = passengers[i];
        eventQ.push(e);

    }


    while(eventQ.size() !=0){


        Event *e1 = eventQ.top();
        clock = e1->exeTime;
        eventQ.pop();
        if(e1->type == 0){

            if(lugProcess > 0){
                e1->exeTime = clock + e1->pass->lugTime;
                e1->type = 1;
                lugProcess--;
                eventQ.push(e1);
            }
            else{
                //LUGcounterlar dolu
                lugProcessQ.push(e1);
            }
        }
        else if(e1->type == 1){

            lugProcess++;
            if (!lugProcessQ.empty()) {
                Event *temp = lugProcessQ.top();
                lugProcessQ.pop();
                temp->exeTime = clock + temp->pass->lugTime;
                temp->type = 1;
                eventQ.push(temp);
                lugProcess--;
            }

            if(secProcess > 0) {

                secProcess--;
                e1->exeTime = clock + e1->pass->secTime;
                e1->type = 2;
                eventQ.push(e1);
            }

            else{
                //SECcounterlar dolu
                secProcessQ.push(e1);
            }

        }
        else {
            secProcess++;
            if(!secProcessQ.empty()) {
                Event *temp = secProcessQ.top();
                temp->type = 2;
                temp->exeTime = clock + temp->pass->secTime;
                eventQ.push(temp);
                secProcessQ.pop();
                secProcess--;
            }
            totalTime += (clock - e1->pass->arriveTime);
            if(clock > e1->pass->boardingTime){
                missedFlight++;
            }

        }


    }


    double Average = (double)totalTime/(double)numOfPass;


    cout << Average << " " << missedFlight << endl;
    file << Average << " " << missedFlight << endl;


    string s = to_string(Average);
    string s1 = to_string(missedFlight);
    return s + " " + s1;

}

string Simulation::makeSim2(vector<Passenger *> passengers, int lugCounter, int secCounter, ofstream &file) {

    priority_queue<Event*, vector<Event*>, compareEvents> eventQ;
    queue<Event*> lugProcessQ;
    queue<Event*> secProcessQ;
    int lugProcess = lugCounter;
    int secProcess = secCounter;
    int clock = 0;
    int totalTime = 0;
    int missedFlight = 0;
    int numOfPass = (int)passengers.size();

    for(int i = 0; i < passengers.size(); i++){

        Event *e = new Event;
        e->type = 0;
        e->lugFinTime = 0;
        e->exeTime = passengers[i]->arriveTime;
        e->pass = passengers[i];
        eventQ.push(e);

    }


    while(eventQ.size() !=0){


        Event *e1 = eventQ.top();
        clock = e1->exeTime;
        eventQ.pop();
        if(e1->type == 0){

            if(lugProcess > 0){
                e1->exeTime = clock + e1->pass->lugTime;
                e1->type = 1;
                lugProcess--;
                eventQ.push(e1);
            }
            else{
                //LUGcounterlar dolu
                lugProcessQ.push(e1);
            }
        }
        else if(e1->type == 1){

            lugProcess++;
            if (!lugProcessQ.empty()) {
                Event *temp = lugProcessQ.front();
                lugProcessQ.pop();
                temp->exeTime = clock + temp->pass->lugTime;
                temp->type = 1;
                eventQ.push(temp);
                lugProcess--;
            }

            if(e1->pass->vip){
                totalTime += (clock - e1->pass->arriveTime);
                if(clock > e1->pass->boardingTime){
                    missedFlight++;
                }
            }

            else if(secProcess > 0) {

                secProcess--;
                e1->exeTime = clock + e1->pass->secTime;
                e1->type = 2;
                eventQ.push(e1);
            }

            else{
                //SECcounterlar dolu
                secProcessQ.push(e1);
            }

        }
        else {
            secProcess++;
            if(!secProcessQ.empty()) {
                Event *temp = secProcessQ.front();
                temp->type = 2;
                temp->exeTime = clock + temp->pass->secTime;
                eventQ.push(temp);
                secProcessQ.pop();
                secProcess--;
            }
            totalTime += (clock - e1->pass->arriveTime);
            if(clock > e1->pass->boardingTime){
                missedFlight++;
            }

        }


    }


    double Average = (double)totalTime/(double)numOfPass;

    cout << Average << " " << missedFlight << endl;
    file << Average << " " << missedFlight << endl;



    string s = to_string(Average);
    string s1 = to_string(missedFlight);
    return s + " " + s1;


}


string Simulation::makeSim3(vector<Passenger *> passengers, int lugCounter, int secCounter, ofstream &file) {


        priority_queue<Event*, vector<Event*>, compareEventsFly> eventQ;
        priority_queue<Event*, vector<Event*>, compareFirstFly> lugProcessQ;
        priority_queue<Event*, vector<Event*>, compareFirstFly> secProcessQ;
        int lugProcess = lugCounter;
        int secProcess = secCounter;
        int clock = 0;
        int totalTime = 0;
        int missedFlight = 0;
        int numOfPass = (int)passengers.size();

        for(int i = 0; i < passengers.size(); i++){

            Event *e = new Event;
            e->type = 0;
            e->lugFinTime = 0;
            e->exeTime = passengers[i]->arriveTime;
            e->pass = passengers[i];
            eventQ.push(e);

        }


        while(eventQ.size() !=0){


            Event *e1 = eventQ.top();
            clock = e1->exeTime;
            eventQ.pop();
            if(e1->type == 0){

                if(lugProcess > 0){
                    e1->exeTime = clock + e1->pass->lugTime;
                    e1->type = 1;
                    lugProcess--;
                    eventQ.push(e1);
                }
                else{
                    //LUGcounterlar dolu
                    lugProcessQ.push(e1);
                }
            }
            else if(e1->type == 1){

                lugProcess++;
                if (!lugProcessQ.empty()) {
                    Event *temp = lugProcessQ.top();
                    lugProcessQ.pop();
                    temp->exeTime = clock + temp->pass->lugTime;
                    temp->type = 1;
                    eventQ.push(temp);
                    lugProcess--;
                }

                if(e1->pass->vip){
                    totalTime += (clock - e1->pass->arriveTime);
                    if(clock > e1->pass->boardingTime){
                        missedFlight++;
                    }
                }

                else if(secProcess > 0) {

                    secProcess--;
                    e1->exeTime = clock + e1->pass->secTime;
                    e1->type = 2;
                    eventQ.push(e1);
                }

                else{
                    //SECcounterlar dolu
                    secProcessQ.push(e1);
                }

            }
            else {
                secProcess++;
                if(!secProcessQ.empty()) {
                    Event *temp = secProcessQ.top();
                    temp->type = 2;
                    temp->exeTime = clock + temp->pass->secTime;
                    eventQ.push(temp);
                    secProcessQ.pop();
                    secProcess--;
                }
                totalTime += (clock - e1->pass->arriveTime);
                if(clock > e1->pass->boardingTime){
                    missedFlight++;
                }

            }


        }


        double Average = (double)totalTime/(double)numOfPass;


        cout << Average << " " << missedFlight << endl;
        file << Average << " " << missedFlight << endl;


        string s = to_string(Average);
        string s1 = to_string(missedFlight);
        return s + " " + s1;


}


string Simulation::makeSim4(vector<Passenger *> passengers, int lugCounter, int secCounter, ofstream &file) {

    priority_queue<Event*, vector<Event*>, compareEvents> eventQ;
    queue<Event*> lugProcessQ;
    queue<Event*> secProcessQ;
    int lugProcess = lugCounter;
    int secProcess = secCounter;
    int clock = 0;
    int totalTime = 0;
    int missedFlight = 0;
    int numOfPass = (int)passengers.size();

    for(int i = 0; i < passengers.size(); i++){

        Event *e = new Event;
        if(passengers[i]->lug){
            e->type = 1;
            e->lugFinTime = 0;
            e->exeTime = passengers[i]->arriveTime;
            e->pass = passengers[i];
            eventQ.push(e);
        }
        else {
            e->type = 0;
            e->lugFinTime = 0;
            e->exeTime = passengers[i]->arriveTime;
            e->pass = passengers[i];
            eventQ.push(e);
        }
    }


    while(eventQ.size() !=0){


        Event *e1 = eventQ.top();
        clock = e1->exeTime;
        eventQ.pop();
        if(e1->type == 0){

            if(lugProcess > 0){
                e1->exeTime = clock + e1->pass->lugTime;
                e1->type = 1;
                lugProcess--;
                eventQ.push(e1);
            }
            else{
                //LUGcounterlar dolu
                lugProcessQ.push(e1);
            }
        }
        else if(e1->type == 1){

            if(!e1->pass->lug) {
                lugProcess++;
                if (!lugProcessQ.empty()) {
                    Event *temp = lugProcessQ.front();
                    lugProcessQ.pop();
                    temp->exeTime = clock + temp->pass->lugTime;
                    temp->type = 1;
                    eventQ.push(temp);
                    lugProcess--;
                }
            }


            if(secProcess > 0) {

                secProcess--;
                e1->exeTime = clock + e1->pass->secTime;
                e1->type = 2;
                eventQ.push(e1);
            }

            else{
                //SECcounterlar dolu
                secProcessQ.push(e1);
            }

        }
        else {
            secProcess++;
            if(!secProcessQ.empty()) {
                Event *temp = secProcessQ.front();
                temp->type = 2;
                temp->exeTime = clock + temp->pass->secTime;
                eventQ.push(temp);
                secProcessQ.pop();
                secProcess--;
            }
            totalTime += (clock - e1->pass->arriveTime);
            if(clock > e1->pass->boardingTime){
                missedFlight++;
            }

        }


    }


    double Average = (double)totalTime/(double)numOfPass;

    cout << Average << " " << missedFlight << endl;
    file << Average << " " << missedFlight << endl;

    string s = to_string(Average);
    string s1 = to_string(missedFlight);
    return s + " " + s1;

}


string Simulation::makeSim5(vector<Passenger *> passengers, int lugCounter, int secCounter, ofstream &file) {

    priority_queue<Event*, vector<Event*>, compareEventsFly> eventQ;
    priority_queue<Event*, vector<Event*>, compareFirstFly> lugProcessQ;
    priority_queue<Event*, vector<Event*>, compareFirstFly> secProcessQ;
    int lugProcess = lugCounter;
    int secProcess = secCounter;
    int clock = 0;
    int totalTime = 0;
    int missedFlight = 0;
    int numOfPass = (int)passengers.size();

    for(int i = 0; i < passengers.size(); i++){

        Event *e = new Event;
        if(passengers[i]->lug){
            e->type = 1;
            e->lugFinTime = 0;
            e->exeTime = passengers[i]->arriveTime;
            e->pass = passengers[i];
            eventQ.push(e);
        }
        else {
            e->type = 0;
            e->lugFinTime = 0;
            e->exeTime = passengers[i]->arriveTime;
            e->pass = passengers[i];
            eventQ.push(e);
        }
    }


    while(eventQ.size() !=0){


        Event *e1 = eventQ.top();
        clock = e1->exeTime;
        eventQ.pop();
        if(e1->type == 0){

            if(lugProcess > 0){
                e1->exeTime = clock + e1->pass->lugTime;
                e1->type = 1;
                lugProcess--;
                eventQ.push(e1);
            }
            else{
                //LUGcounterlar dolu
                lugProcessQ.push(e1);
            }
        }
        else if(e1->type == 1){

            if(!e1->pass->lug) {
                lugProcess++;
                if (!lugProcessQ.empty()) {
                    Event *temp = lugProcessQ.top();
                    lugProcessQ.pop();
                    temp->exeTime = clock + temp->pass->lugTime;
                    temp->type = 1;
                    eventQ.push(temp);
                    lugProcess--;
                }
            }

            if(secProcess > 0) {

                secProcess--;
                e1->exeTime = clock + e1->pass->secTime;
                e1->type = 2;
                eventQ.push(e1);
            }

            else{
                //SECcounterlar dolu
                secProcessQ.push(e1);
            }

        }
        else {
            secProcess++;
            if(!secProcessQ.empty()) {
                Event *temp = secProcessQ.top();
                temp->type = 2;
                temp->exeTime = clock + temp->pass->secTime;
                eventQ.push(temp);
                secProcessQ.pop();
                secProcess--;
            }
            totalTime += (clock - e1->pass->arriveTime);
            if(clock > e1->pass->boardingTime){
                missedFlight++;
            }

        }


    }


    double Average = (double)totalTime/(double)numOfPass;


    cout << Average << " " << missedFlight << endl;
    file << Average << " " << missedFlight << endl;


    string s = to_string(Average);
    string s1 = to_string(missedFlight);
    return s + " " + s1;

}


string Simulation::makeSim6(vector<Passenger *> passengers, int lugCounter, int secCounter, ofstream &file) {

    priority_queue<Event*, vector<Event*>, compareEvents> eventQ;
    queue<Event*> lugProcessQ;
    queue<Event*> secProcessQ;
    int lugProcess = lugCounter;
    int secProcess = secCounter;
    int clock = 0;
    int totalTime = 0;
    int missedFlight = 0;
    int numOfPass = (int)passengers.size();

    for(int i = 0; i < passengers.size(); i++){

        Event *e = new Event;
        if(passengers[i]->lug){
            e->type = 1;
            e->lugFinTime = 0;
            e->exeTime = passengers[i]->arriveTime;
            e->pass = passengers[i];
            eventQ.push(e);
        }
        else {
            e->type = 0;
            e->lugFinTime = 0;
            e->exeTime = passengers[i]->arriveTime;
            e->pass = passengers[i];
            eventQ.push(e);
        }
    }


    while(eventQ.size() !=0){


        Event *e1 = eventQ.top();
        clock = e1->exeTime;
        eventQ.pop();
        if(e1->type == 0){

            if(lugProcess > 0){
                e1->exeTime = clock + e1->pass->lugTime;
                e1->type = 1;
                lugProcess--;
                eventQ.push(e1);
            }
            else{
                //LUGcounterlar dolu
                lugProcessQ.push(e1);
            }
        }
        else if(e1->type == 1){


            if(!e1->pass->lug) {
                lugProcess++;
                if (!lugProcessQ.empty()) {
                    Event *temp = lugProcessQ.front();
                    lugProcessQ.pop();
                    temp->exeTime = clock + temp->pass->lugTime;
                    temp->type = 1;
                    eventQ.push(temp);
                    lugProcess--;
                }
            }

            if(e1->pass->vip){
                totalTime += (clock - e1->pass->arriveTime);
                if(clock > e1->pass->boardingTime){
                    missedFlight++;
                }
            }

            else if(secProcess > 0) {

                secProcess--;
                e1->exeTime = clock + e1->pass->secTime;
                e1->type = 2;
                eventQ.push(e1);
            }

            else{
                //SECcounterlar dolu
                secProcessQ.push(e1);
            }

        }
        else {
            secProcess++;
            if(!secProcessQ.empty()) {
                Event *temp = secProcessQ.front();
                temp->type = 2;
                temp->exeTime = clock + temp->pass->secTime;
                eventQ.push(temp);
                secProcessQ.pop();
                secProcess--;
            }
            totalTime += (clock - e1->pass->arriveTime);
            if(clock > e1->pass->boardingTime){
                missedFlight++;
            }

        }


    }


    double Average = (double)totalTime/(double)numOfPass;

    cout << Average << " " << missedFlight << endl;
    file << Average << " " << missedFlight << endl;

    string s = to_string(Average);
    string s1 = to_string(missedFlight);
    return s + " " + s1;


}


string Simulation::makeSim7(vector<Passenger *> passengers, int lugCounter, int secCounter, ofstream &file) {

    priority_queue<Event*, vector<Event*>, compareEventsFly> eventQ;
    priority_queue<Event*, vector<Event*>, compareFirstFly> lugProcessQ;
    priority_queue<Event*, vector<Event*>, compareFirstFly> secProcessQ;
    int lugProcess = lugCounter;
    int secProcess = secCounter;
    int clock = 0;
    int totalTime = 0;
    int missedFlight = 0;
    int numOfPass = (int)passengers.size();

    for(int i = 0; i < passengers.size(); i++){

        Event *e = new Event;
        if(passengers[i]->lug){
            e->type = 1;
            e->lugFinTime = 0;
            e->exeTime = passengers[i]->arriveTime;
            e->pass = passengers[i];
            eventQ.push(e);
        }
        else {
            e->type = 0;
            e->lugFinTime = 0;
            e->exeTime = passengers[i]->arriveTime;
            e->pass = passengers[i];
            eventQ.push(e);
        }
    }


    while(eventQ.size() !=0){


        Event *e1 = eventQ.top();
        clock = e1->exeTime;
        eventQ.pop();
        if(e1->type == 0){

            if(lugProcess > 0){
                e1->exeTime = clock + e1->pass->lugTime;
                e1->type = 1;
                lugProcess--;
                eventQ.push(e1);
            }
            else{
                //LUGcounterlar dolu
                lugProcessQ.push(e1);
            }
        }
        else if(e1->type == 1){

            if(!e1->pass->lug) {
                lugProcess++;
                if (!lugProcessQ.empty()) {
                    Event *temp = lugProcessQ.top();
                    lugProcessQ.pop();
                    temp->exeTime = clock + temp->pass->lugTime;
                    temp->type = 1;
                    eventQ.push(temp);
                    lugProcess--;
                }
            }

            if(e1->pass->vip){
                totalTime += (clock - e1->pass->arriveTime);
                if(clock > e1->pass->boardingTime){
                    missedFlight++;
                }
            }

            else if(secProcess > 0) {

                secProcess--;
                e1->exeTime = clock + e1->pass->secTime;
                e1->type = 2;
                eventQ.push(e1);
            }

            else{
                //SECcounterlar dolu
                secProcessQ.push(e1);
            }


        }
        else {
            secProcess++;
            if(!secProcessQ.empty()) {
                Event *temp = secProcessQ.top();
                temp->type = 2;
                temp->exeTime = clock + temp->pass->secTime;
                eventQ.push(temp);
                secProcessQ.pop();
                secProcess--;
            }
            totalTime += (clock - e1->pass->arriveTime);
            if(clock > e1->pass->boardingTime){
                missedFlight++;
            }

        }


    }


    double Average = (double)totalTime/(double)numOfPass;


    cout << Average << " " << missedFlight << endl;
    file << Average << " " << missedFlight << endl;


    string s = to_string(Average);
    string s1 = to_string(missedFlight);
    return s + " " + s1;

}