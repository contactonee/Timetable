#ifndef TIMESLOT_H
#define TIMESLOT_H

#include "Time.h"

class Timeslot {
public:
    Timeslot(Time *begin, Time *end);
    static bool overlaps(Timeslot *a, Timeslot *b);
private:
    Time *begin;
    Time *end;
};

#endif
