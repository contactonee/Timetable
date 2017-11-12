#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>


#include "Faculty.h"
#include "Course.h"
#include "Room.h"
#include "Group.h"
#include "Lesson.h"



int main() {

    std::vector < Course* > courses;

    std::vector < Group* > groups;

    groups.push_back(new Group("EEEY1", 60));
    groups.push_back(new Group("MEY1", 60));
    groups.push_back(new Group("CHEY1", 60));
    groups.push_back(new Group("CEY1", 60));

    std::vector < Lesson* > timetable;

    std::vector < Room* > room;
    room.push_back(new Room("Orange Hall", 240));
    room.push_back(new Room("6.552", 60, 0, 1));
    room.push_back(new Room("3.221", 60));
    room.push_back(new Room("3.222", 5, 1, 0));


    // Sort by type (lectures only, complab, lab, both) and then by capacity
    std::sort(room.begin(), room.end(), [](Room* a, Room* b) {
        if(a->compLab + 2 * a->lab < b->compLab + 2 * b->lab) {
            return 1;
        }
        else if(2 * a->compLab + a->lab == 2 * b->compLab + b->lab) {
            if(a->getSize() < b->getSize()) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            return 0;
        }
    });


    Course *c = new Course("Materials", 1, 5);
    c->assignFaculty(new Faculty("Asma Perveen"));

    for(int i = 0; i < groups.size(); i++) {
        c->enrollGroup(groups[i]);
    }

    c->evaluateSubgroups();

    courses.push_back(c);

    c = new Course("Mechanics", 1, 5);
    c->assignFaculty(new Faculty("Anatoli Vakhguelt"));

    for(int i = 0; i < groups.size(); i++) {
        c->enrollGroup(groups[i]);
    }
    c->evaluateSubgroups();
    courses.push_back(c);


    Room* candidate;


    for(int ij = 0; ij < courses.size(); ij++) {
        c = courses[ij];
        for(int i = 0; i < c->L_groups.size(); i++) {
            candidate = NULL;
            bool f = 0;
            for(int j = 0; j < room.size() && !f; j++) {
                if(room[j]->getSize() >= c->L_groups[i]->size && !room[j]->empty()) {
                    candidate = room[j];
                    for(int k = 0; k < 20 && !f; k++) {
                        if(candidate->slots[k]->available && c->getFaculty()->slots[k]->available && c->L_groups[i]->slots[k]->available) {
                            Lesson *l = new Lesson(c,
                                c->L_groups[i],
                                candidate,
                                candidate->slots[k]
                            );
                            candidate->reserve(candidate->slots[k]);
                            c->getFaculty()->reserve(c->getFaculty()->slots[k]);
                            c->L_groups[i]->reserve(c->L_groups[i]->slots[k]);
                            timetable.push_back(l);
                            f = 1;
                        }
                    }
                }
            }
        }


        for(int i = 0; i < c->T_groups.size(); i++) {
            candidate = NULL;
            bool f = 0;
            for(int j = 0; j < room.size() && !f; j++) {
                if(room[j]->getSize() >= c->T_groups[i]->size && !room[j]->empty()) {
                    candidate = room[j];
                    for(int k = 0; k < 20 && !f; k++) {
                        if(candidate->slots[k]->available && c->getFaculty()->slots[k]->available && c->T_groups[i]->slots[k]->available) {
                            Lesson *l = new Lesson(c,
                                c->T_groups[i],
                                candidate,
                                candidate->slots[k]
                            );
                            candidate->reserve(candidate->slots[k]);
                            c->getFaculty()->reserve(c->getFaculty()->slots[k]);
                            c->T_groups[i]->reserve(c->T_groups[i]->slots[k]);
                            timetable.push_back(l);
                            f = 1;
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < timetable.size();i++) {
        timetable[i]->print();
    }
}
