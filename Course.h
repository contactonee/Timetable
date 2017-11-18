#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>

#include "Group.h"
#include "Faculty.h"
#include "Student.h"

class Course {

public:
    Course(std::string name,
        int lectures = 0,
        int tutorials = 0,
        int labs = 0,
        int complabs = 0);

    int L, T, Lb, CLb;

    void assignFaculty(Faculty* prof);
    Faculty* faculty();

    std::string name();

    void enrollGroup(Group* group);
    std::vector < Group* > groups;
    std::vector < Student* > students;

    void reg();

private:
    Faculty* prof;
    std::string Name;
};

#endif // COURSE_H
