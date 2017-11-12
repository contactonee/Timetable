#include "Timeslot.h"

Timeslot::Timeslot(Time *begin, Time *end) {
    if(begin->getTimestamp() > end->getTimestamp()) {
        std::swap(begin, end);
    }
    Timeslot::begin = begin;
    Timeslot::end = end;
}

Timeslot::Timeslot(int day, int start_hours, int finish_hours) {
    begin = new Time(day, start_hours);
    end = new Time(day, finish_hours);
}

Timeslot::Timeslot(int day,
        int start_hours,
        int start_minutes,
        int finish_hours,
        int finish_minutes) {

    begin = new Time(day, start_hours, start_minutes);
    end = new Time(day, finish_hours, finish_minutes);
}


bool Timeslot::overlaps(Timeslot *a, Timeslot *b) {

    if(a->begin->getTimestamp() > b->begin->getTimestamp()) {
        std::swap(a, b);
    }
    if(a->end->getTimestamp() >= b->begin->getTimestamp()) {
        return true;
    }
    else {
        return false;
    }

}

Time* Timeslot::getBegin() {
    return begin;
}
Time* Timeslot::getEnd() {
    return end;
}
