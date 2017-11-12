#include "Faculty.h"

Faculty::Faculty (std::string name) {
    Faculty::name = name;


    for(int i = 1; i <= 5; i++) {
        slots.push_back(new Timeslot(i, 9, 11));
        slots.push_back(new Timeslot(i, 11, 13));
        slots.push_back(new Timeslot(i, 14, 16));
        slots.push_back(new Timeslot(i, 16, 18));
    }
}
