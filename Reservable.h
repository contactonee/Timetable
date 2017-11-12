#ifndef RESERVABLE_H
#define RESERVABLE_H

#include <vector>

#include "Timeslot.h"

class Reservable {
public:
    Reservable();
    Timeslot* next();
    void reserve(Timeslot* slot);

    bool empty();

    std::vector < Timeslot* > slots;
    int reserved = 0;

private:
};


#endif // RESERVABLE_H
