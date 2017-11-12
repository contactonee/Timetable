#ifndef SHOWABLE_H
#define SHOWABLE_H

#include "Lesson.h"
#include <vector>

class Showable {
public:
    Showable();
    void show();
    void addLesson(Lesson *lesson);
private:
    std::vector < Lesson* > lessons;
    bool updated = false;
};


#endif // SHOWABLE_H
