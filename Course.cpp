#include "Course.h"
#include <iostream>
#include <string>

Course::Course(std::string title,
        int lec,
        int t,
        int l,
        int c) {
    Course::title = title;

    L_groups.resize(lec);
    T_groups.resize(t);
    Lb_groups.resize(l);
    CLb_groups.resize(c);
}

void Course::assignFaculty(Faculty* prof) {
    faculty = prof;
}
Faculty* Course::getFaculty() {
    return faculty;
}
std::string Course::getTitle() {
    return title;
}

void Course::enrollGroup(Group* group) {
    enrolled += group->size;
    groups.push_back(group);
}

void Course::evaluateSubgroups() {

    std::string combName = "";
    for(int i = 0; i < groups.size(); i++) {
        if(i > 0) {
            combName += "+";
        }
        combName += groups[i]->name;
    }
    combName += (", " + title);

    int ssz, rem;

    if(!L_groups.empty()) {
        ssz = enrolled / L_groups.size();
        rem = enrolled;
        for(int i = 0; i < L_groups.size(); i++) {
            std::string num = "1";
            num[0] += i;
            L_groups[i] = new Group(combName + " Lecture Subgroup " + num,
                std::min(ssz, rem));
            rem -= ssz;
        }
    }

    if(!T_groups.empty()) {
        ssz = enrolled / T_groups.size();
        rem = enrolled;
        for(int i = 0; i < T_groups.size(); i++) {
            std::string num = "1";
            num[0] += i;
            T_groups[i] = new Group(combName + " Tutorial Subgroup " + num,
                std::min(ssz, rem));
            rem -= ssz;
        }
    }

    if(!Lb_groups.empty()) {
        ssz = enrolled / Lb_groups.size();
        rem = enrolled;
        for(int i = 0; i < Lb_groups.size(); i++) {
            std::string num = "1";
            num[0] += i;
            Lb_groups[i] = new Group(combName + " Labs Subgroup " + num,
                std::min(ssz, rem));
            rem -= ssz;
        }
    }

    if(!CLb_groups.empty()) {
        ssz = enrolled / CLb_groups.size();
        rem = enrolled;
        for(int i = 0; i < CLb_groups.size(); i++) {
            std::string num = "1";
            num[0] += i;
            CLb_groups[i] = new Group(combName + " CompLabs Subgroup " + num,
                std::min(ssz, rem));
            rem -= ssz;
        }
    }
}
