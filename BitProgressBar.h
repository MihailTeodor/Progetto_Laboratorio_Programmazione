//
// Created by utente on 14/09/2016.
//

#include "Observer.h"
#include <iostream>
#ifndef PROGETTO_LABORATORIO_PROGRAMMAZIONE_BITPROGRESSBAR_H
#define PROGETTO_LABORATORIO_PROGRAMMAZIONE_BITPROGRESSBAR_H
using namespace std;

class BitProgressBar:public Observer{
public:
    BitProgressBar (Subject* s):subject(s), bitPercentuale(0){
        subject->registerObserver(this);
    }

    ~BitProgressBar(){
        subject->removeObserver(this);
    }

    void update(){
        bitPercentuale=subject->getBitPercentage();
        display();
    }

    void display(){
        cout<<"percentuale in bit: "<<bitPercentuale<<"% "<<endl;
    }

    double getBitPercentuale() const {
        return bitPercentuale;
    }

    void setBitPercentuale(double bitPercentuale) {
        BitProgressBar::bitPercentuale = bitPercentuale;
    }

    Subject *getSubject() const {
        return subject;
    }

private:
    Subject* subject;
   double bitPercentuale;
};
#endif //PROGETTO_LABORATORIO_PROGRAMMAZIONE_BITPROGRESSBAR_H
