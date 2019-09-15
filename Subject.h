//
// Created by utente on 12/09/2016.
//

#ifndef PROGETTO_LABORATORIO_PROGRAMMAZIONE_SUBJECT_H
#define PROGETTO_LABORATORIO_PROGRAMMAZIONE_SUBJECT_H



#include "Observer.h"

class Subject{
public:

    virtual void registerObserver(Observer* o) =0;
    virtual void removeObserver(Observer* o) =0;
    virtual void notifyObserver()  =0;
    virtual int getPercentage() = 0;
    virtual double getBitPercentage() = 0;

};
#endif //PROGETTO_LABORATORIO_PROGRAMMAZIONE_SUBJECT_H
