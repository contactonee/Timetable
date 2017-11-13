#include "Reservable.h"

Reservable::Reservable() {}


void Reservable::reserve(Timeslot* slot) {
    slot->available = false;
    Reserved++;
}

void Reservable::reserve(int k) {
    slots[k]->available = false;
    Reserved++;
}

int Reservable::getAvailable() {
    return Total - Reserved;
}

void Reservable::InitSlots() {
    Total = 20;
    slots.resize(20);
    for(int i = 1; i <= 5; i++) {
        slots.push_back(new Timeslot(i, 9, 0, 10, 50));
        slots.push_back(new Timeslot(i, 11, 0, 12, 50));
        slots.push_back(new Timeslot(i, 14, 0, 15, 50));
        slots.push_back(new Timeslot(i, 16, 0, 17, 50));
    }
}
