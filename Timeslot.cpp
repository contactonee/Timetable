#include "Timeslot.h"

Timeslot::Timeslot(Time begin, Time end) {
    if(begin.timestamp() > end.timestamp()) {
        std::swap(begin, end);
    }
    Begin = &begin;
    End = &end;
}

Timeslot::Timeslot(int day, int start_hours, int finish_hours) {
    Begin = new Time(day, start_hours);
    End = new Time(day, finish_hours);
}

Timeslot::Timeslot(int day,
        int start_hours,
        int start_minutes,
        int finish_hours,
        int finish_minutes) {

    Begin = new Time(day, start_hours, start_minutes);
    End = new Time(day, finish_hours, finish_minutes);
}

Time Timeslot::begin() {
    return *Begin;
}
Time Timeslot::end() {
    return *End;
}
