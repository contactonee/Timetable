#include "Student.h"

int Student::cnt = 0;

Student::Student() {
    id = ++cnt;

    InitSlots();
}
