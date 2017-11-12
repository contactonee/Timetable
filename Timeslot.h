#ifndef TIMESLOT_H
#define TIMESLOT_H

#include "Time.h"

class Timeslot {
public:
    Timeslot(Time *begin, Time *end);
    Timeslot(int day, int start_hours, int finish_hours);
    Timeslot(int day,
        int start_hours,
        int start_minutes,
        int finish_hours,
        int finish_minutes);

    static bool overlaps(Timeslot *a, Timeslot *b);
    Time* getBegin();
    Time* getEnd();

    bool available = true;


private:
    Time *begin;
    Time *end;
};

#endif
