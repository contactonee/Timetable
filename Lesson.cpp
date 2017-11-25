#include "Lesson.h"
#include <cstdio>
#include "Time.h"

Lesson::Lesson(Course* course,
        std::string type,
        Group* group,
        Room* room,
        Timeslot* timeslot){
    Lesson::course = course;
    Lesson::group = group;
    Lesson::room = room;
    Lesson::timeslot = timeslot;
}

void Lesson::print() {

    Time t1 = timeslot->begin();
    Time t2 = timeslot->end();

    std::printf("%s %s\n%s\n%s %02d:%02d - %02d:%02d\nGroup of IDs: %d...%d\nVenue: %s\n\n\n",
        course->name().c_str(),
        type.c_str(),
        course->faculty()->name.c_str(),
        days[t1.day()].c_str(),
        t1.hours(),
        t1.minutes(),
        t2.hours(),
        t2.minutes(),
        course->students[l]->id,
        course->students[r]->id,
        cand->name().c_str());



}



