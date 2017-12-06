#include "Course.h"
#include <iostream>
#include <string>

Course::Course(std::string abbr,
        std::string name,
        int lec,
        int t,
        int l,
        int c) {
    Abbr = abbr;
    Name = name;
    L = lec;
    T = t;
    Lb = l;
    CLb = c;
}

void Course::assignFaculty(Faculty* prof) {
    Course::prof = prof;
}
Faculty* Course::faculty() {
    return prof;
}
std::string Course::name() {
    return Name;
}
std::string Course::abbr() {
    return Abbr;
}

void Course::enrollGroup(Group* group) {
    groups.push_back(group);
    for(int i = 0; i < group->size(); i++) {
        students.push_back(group->students[i]);
    }
}
