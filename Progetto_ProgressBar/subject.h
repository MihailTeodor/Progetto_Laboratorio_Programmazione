#ifndef SUBJECT_H
#define SUBJECT_H
#include "Observer.h"

class Subject{
public:
    virtual void registerObserver(Observer* o) =0;
    virtual void removeObserver(Observer* o) =0;
    virtual void notifyObserver()  =0;
    virtual int getPercentage() = 0;
    virtual double getBitPercentage() = 0;
};
#endif // SUBJECT_H
