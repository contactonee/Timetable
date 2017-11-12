#include "Showable.h"
#include "Time.h"
#include <cstdio>

Showable::Showable() {}

void Showable::addLesson(Lesson *lesson) {
    lessons.push_back(lesson);
    updated = true;
}

void Showable::show() {
    for(auto lesson : lessons) {
        Time *st = lesson->timeslot->getBegin();
        Time *fi = lesson->timeslot->getEnd();
        int h1 = st->getHours();
        int m1 = st->getMinutes();
        int h2 = fi->getHours();
        int m2 = fi->getMinutes();
        delete st;
        delete fi;
        std::printf("Start:\t%02d:%02d\nEnd:\t%02d:%02d\n\n", h1, m1, h2, m2);
    }
}
