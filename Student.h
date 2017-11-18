#ifndef STUDENT_H
#define STUDENT_H

#include "Reservable.h"

class Student : public Reservable {
public:

    static int cnt;
    Student();
    int id;

};


#endif // STUDENT_H
