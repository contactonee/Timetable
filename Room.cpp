#include "Room.h"
#include <iostream>

Room::Room(std::string name,
        int size,
        bool laboratory,
        bool computers) {

    Name = name;
    Size = size;

    compLab = computers;
    lab = laboratory;

    InitSlots();

}
std::string Room::name() {
    return Name;
}
int Room::size() {
    return Size;
}
