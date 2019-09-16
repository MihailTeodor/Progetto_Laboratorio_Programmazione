#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H
#include "Observer.h"
#include "Subject.h"
#include "FileLoader.h"
#include <iostream>
#include <QObject>

using namespace std;

class ProgressBar :public  QObject, public Observer {
Q_OBJECT
public: signals:
   void display(int newValue);
public:
    ProgressBar (Subject* s):file(s), percentuale(0){
        file->registerObserver(this);
    }

    ~ProgressBar(){
        file->removeObserver(this);
    }
    void update() {
        percentuale=file->getPercentage();
        emit display(percentuale);
    }

    int getPercentuale() const {
        return percentuale;
    }

    void setPercentuale(int percentuale) {
        ProgressBar::percentuale = percentuale;
    }

   Subject *getFile() const {
        return file;
    }
private:
    Subject* file;
    int percentuale;
};
#endif // PROGRESSBAR_H
