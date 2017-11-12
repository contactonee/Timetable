#ifndef LESSON_H
#define LESSON_H

#include "Room.h"
#include "Timeslot.h"
#include "Course.h"
#include "Group.h"

class Lesson {
public:
    Lesson(Course* course,
        Group* group,
        Room* room,
        Timeslot* timeslot);

    void print();


    Course* course;
    Group* group;
    Room* room;
    Timeslot* timeslot;
};

#endif
