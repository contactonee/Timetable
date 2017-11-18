#ifndef RESERVABLE_H
#define RESERVABLE_H

#include <vector>
#include "Timeslot.h"

class Reservable {
public:
    std::vector < Timeslot* > slots;

    Reservable();

    void reserve(Timeslot* slot);
    void reserve(int k);

    int getAvailable();

    void InitSlots();

private:
    int Reserved = 0;
    int Total = 0;
};


#endif // RESERVABLE_H
