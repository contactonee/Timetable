#include "Room.h"
#include <iostream>

Room::Room(std::string title,
        int size,
        bool laboratory,
        bool computers) {
    Room::title = title;
    Room::size = size;
    compLab = computers;
    lab = laboratory;
    for(int i = 1; i <= 5; i++) {

        slots.push_back(new Timeslot(i, 9, 11));
        slots.push_back(new Timeslot(i, 11, 13));
        slots.push_back(new Timeslot(i, 14, 16));
        slots.push_back(new Timeslot(i, 16, 18));
    }
}
std::string Room::getTitle() {
    return title;
}
int Room::getSize() {
    return size;
}
