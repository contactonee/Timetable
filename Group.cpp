#include "Group.h"

Group::Group(std::string name, int size) {
    Group::name = name;
    Group::size = size;

    for(int i = 1; i <= 5; i++) {

        slots.push_back(new Timeslot(i, 9, 11));
        slots.push_back(new Timeslot(i, 11, 13));
        slots.push_back(new Timeslot(i, 14, 16));
        slots.push_back(new Timeslot(i, 16, 18));
    }
}
