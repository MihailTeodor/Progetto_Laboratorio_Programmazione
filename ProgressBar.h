//
// Created by utente on 12/09/2016.
//

#ifndef PROGETTO_LABORATORIO_PROGRAMMAZIONE_PROGRESSBAR_H
#define PROGETTO_LABORATORIO_PROGRAMMAZIONE_PROGRESSBAR_H



#include "Observer.h"
#include "Subject.h"
#include "FileLoader.h"
#include <iostream>


using namespace std;

class ProgressBar : public Observer{

public:

    ProgressBar (Subject* s):file(s), percentuale(0){
        file->registerObserver(this);
    }

    ~ProgressBar(){
        file->removeObserver(this);
    }

    void display(){
        cout<<"Stato caricamento: "<<percentuale<<"%"<<endl;
    }

    void update() {
        percentuale=file->getPercentage();
        display();
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
#endif //PROGETTO_LABORATORIO_PROGRAMMAZIONE_PROGRESSBAR_H
