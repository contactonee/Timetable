#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>

#include "Group.h"
#include "Faculty.h"
#include "Student.h"

class Course {

public:
    Course(std::string abbr,
        std::string name,
        int lectures = 0,
        int tutorials = 0,
        int labs = 0,
        int complabs = 0);

    int L, T, Lb, CLb;

    void assignFaculty(Faculty* prof);
    Faculty* faculty();

    std::string name();
    std::string abbr();

    void enrollGroup(Group* group);
    std::vector < Group* > groups;
    std::vector < Student* > students;

private:
    Faculty* prof;
    std::string Name;
    std::string Abbr;
};

#endif // COURSE_H
