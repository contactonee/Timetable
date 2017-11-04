#ifndef LESSON_H
#define LESSON_H

#include "Room.h"
#include "Timeslot.h"

class Lesson {
public:
    Lesson();
    Room *room;
    Timeslot *timeslot;

};

#endif
