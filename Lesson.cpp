#include "Lesson.h"
#include <iostream>
#include "Time.h"

Lesson::Lesson(Course* course,
        Group* group,
        Room* room,
        Timeslot* timeslot){
    Lesson::course = course;
    Lesson::group = group;
    Lesson::room = room;
    Lesson::timeslot = timeslot;
}

void Lesson::print() {

    std::cout << timeslot->getBegin()->getDay() << " " << timeslot->getBegin()->getHours() << ":00 - ";
    std::cout << timeslot->getEnd()->getHours() << ":00\n";

    std::cout << course->getTitle() << " by Prof. ";
    std::cout << course->getFaculty()->name << "\n";

    std::cout << group->name << "\n";

    std::cout << "Venue: " << room->getTitle() << "\n\n";



}



