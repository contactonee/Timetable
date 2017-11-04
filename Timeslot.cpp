#include "Timeslot.h"

Timeslot::Timeslot(Time *begin, Time *end) {
    if(begin->getTimestamp() > end->getTimestamp()) {
        std::swap(begin, end);
    }
    Timeslot::begin = begin;
    Timeslot::end = end;
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
