#ifndef BITPROGRESSBAR_H
#define BITPROGRESSBAR_H

#include "observer.h"
#include "subject.h"
#include <iostream>
#include <QObject>

using namespace std;

class BitProgressBar: public QObject, public Observer{

    Q_OBJECT
public:
    BitProgressBar (Subject* s):subject(s), bitPercentuale(0){
        subject->registerObserver(this);
    }

    ~BitProgressBar(){
        subject->removeObserver(this);
    }

    void update(){
        bitPercentuale=subject->getBitPercentage();
        display(bitPercentuale);
    }
public: signals:
    void display(int);
    public:
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
#endif // BITPROGRESSBAR_H
