#include "Reservable.h"

Reservable::Reservable() {}


Timeslot* Reservable::next() {
    for(int i = 0; i < slots.size(); i++) {
        if(slots[i] != NULL && slots[i]->available) {
            return slots[i];
        }
    }
    return NULL;
}

void Reservable::reserve(Timeslot* slot) {
    for(int i = 0; i < slots.size(); i++) {
        if(slots[i] != NULL && slots[i]->getBegin()->getTimestamp() == slot->getBegin()->getTimestamp()) {
            slots[i]->available = 0;
            reserved++;
        }
    }
}
bool Reservable::empty() {
    return reserved >= 20;
}
