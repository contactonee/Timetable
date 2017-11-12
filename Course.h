#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>

#include "Group.h"
#include "Faculty.h"

class Course {

public:
    Course(std::string title,
        int lectures = 0,
        int tutorials = 0,
        int labs = 0,
        int complabs = 0);

    int enrolled = 0;

    void assignFaculty(Faculty* prof);
    Faculty* getFaculty();

    std::string getTitle();

    void enrollGroup(Group* group);
    std::vector < Group* > groups, L_groups, T_groups, CLb_groups, Lb_groups;

    void evaluateSubgroups();

private:
    Faculty* faculty;
    std::string title;
};

#endif // COURSE_H
