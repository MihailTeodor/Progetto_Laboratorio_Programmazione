//
// Created by utente on 12/09/2016.
//

#ifndef PROGETTO_LABORATORIO_PROGRAMMAZIONE_OBSERVER_H
#define PROGETTO_LABORATORIO_PROGRAMMAZIONE_OBSERVER_H



#include "Subject.h"


class Observer{

public:
    virtual ~Observer() {}
    virtual void update() =0;

};
#endif //PROGETTO_LABORATORIO_PROGRAMMAZIONE_OBSERVER_H
