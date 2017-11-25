#ifndef LESSON_H
#define LESSON_H

#include "Course.h"
#include "Group.h"
#include "Room.h"
#include "Timeslot.h"
#include <string>

class Lesson {
public:
    Lesson(Course* course,
            std::string type
            Group* group,
            Room* room,
            Timeslot* timeslot);

    void print();


private:
    Course* course;
    Group* group;
    Room* room;
    Timeslot* timeslot;
};

#endif // LESSON_H
