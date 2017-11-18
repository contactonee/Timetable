#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <map>


#include "Group.h"
#include "Faculty.h"
#include "Course.h"
#include "Room.h"


std::vector < Group* > groups;
std::vector < Course* > courses;
std::vector < Room* > rooms;
std::map < std::string, Course* > courseMap;
std::string days[] = {"", "Mon", "Tue", "Wed", "Thu", "Fri"};


bool roomsCmp(Room* a, Room* b) {

    if(2 * a->lab + a->compLab < 2 * b->lab + b->compLab) {
        return 1;
    }
    else if(2 * a->lab + a->compLab == 2 * b->lab + b->compLab) {
        if(a->size() < b->size()) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}

void reg(Course* c, std::string type, int n) {

    if(n == 0) {
        return;
    }

    // Lab
    bool lab = 0;
    if(type.size() == 3) {
        lab = 1;
    }

    // CompLab
    bool comp = 0;
    if(type[0] == 'C') {
        comp = 1;
    }

    int gsz = c->students.size() / n;
    for(int i = 1, l = 0, r = gsz - 1; i <= n; i++, l +=  gsz, r += gsz) {


        Room* cand = NULL;
        bool done = 0;
        for(int j = 0; j < rooms.size() && !done; j++) {
            if(rooms[j]->getAvailable() > 0
                    && rooms[j]->size() >= gsz
                    && rooms[j]->compLab >= comp
                    && rooms[j]->lab >= lab) {

                cand = rooms[j];

                for(int k = 0; k < 20 && !done; k++) {

                    bool studentsAvailable = 1;
                    for(int p = l; p <= r; p++) {
                        if(!c->students[p]->slots[k]->available){
                            studentsAvailable = 0;
                            break;
                        }
                    }

                    if(cand->slots[k]->available
                            && c->faculty()->slots[k]->available
                            && studentsAvailable) {

                        cand->reserve(k);
                        c->faculty()->reserve(k);
                        for(int p = l; p <= r; p++) {
                            c->students[p]->reserve(k);
                        }

                        Time t1 = cand->slots[k]->begin();
                        Time t2 = cand->slots[k]->end();
                        std::printf("%s %s\n%s %02d:%02d - %02d:%02d\nGroup of IDs: %d...%d\nVenue: %s\n\n\n",
                            c->name().c_str(),
                            type.c_str(),
                            days[t1.day()].c_str(),
                            t1.hours(),
                            t1.minutes(),
                            t2.hours(),
                            t2.minutes(),
                            c->students[l]->id,
                            c->students[r]->id,
                            cand->name().c_str());
                        done = 1;
                    }
                }
            }
        }
    }
}


int main() {

    freopen("output.txt", "w", stdout);

    std::ifstream fin;
    int n;
    char input[256];


    fin.open("rooms.txt", std::ifstream::in);
    fin >> n;
    fin.getline(input, 256);

    while(rooms.size() < n) {

        fin.getline(input, 256);
        while(fin.gcount() <= 1) {
            fin.getline(input, 256);
        }

        int i = 0;

        std::string name = "";
        int sz = 0;
        bool complab = 0, lab = 0;


        // Fill the name
        for(i = 0; input[i] != ','; i++) {
            name += input[i];
        }

        // Skip comma and spaces
        for(++i; input[i] == ' '; i++);

        // Fill the size
        for(; input[i] >= '0' && input[i] <= '9'; i++) {
            sz *= 10;
            sz += input[i] - '0';
        }

        // Find options such as CompLab or Lab
        for(; i < fin.gcount() - 1; i++) {
            if((input[i] == 'c' || input[i] == 'C') && (input[i - 1] == ',' || input[i - 1] == ' ')) {
                complab = 1;
            }
            if((input[i] == 'l' || input[i] == 'L') && (input[i - 1] == ',' || input[i - 1] == ' ')) {
                lab = 1;
            }
        }

        // Push new room
        rooms.push_back(new Room(name, sz, lab, complab));
    }
    fin.close();

    std::sort(rooms.begin(), rooms.end(), roomsCmp);


    fin.open("courses.txt", std::ifstream::in);
    fin >> n;
    fin.getline(input, 256);

    while(courses.size() < n) {

        fin.getline(input, 256);
        while(fin.gcount() <= 1) {
            fin.getline(input, 256);
        }
        int i = 0;

        // Fill the course name
        std::string name = "";
        for(i = 0; i < fin.gcount() - 1; i++){
            name += input[i];
        }

        // Fill the faculty name
        fin.getline(input, 256);
        std::string prof = "";
        for(i = 0; i < fin.gcount() - 1; i++){
            prof += input[i];
        }

        // Parse course groups
        int L = 0, T = 0, Lb = 0, CLb = 0;
        fin.getline(input, 256);
        for(i = 1; i < fin.gcount() - 1; i++) {
            if(input[i] == 'L') {
                if(input[i + 1] == 'b') {
                    if(input[i - 1] == 'C') {
                        CLb = input[i - 2] - '0';
                    }
                    else {
                        Lb = input[i - 1] - '0';
                    }
                }
                else {
                    L = input[i - 1] - '0';
                }
            }
            if(input[i] == 'T') {
                T = input[i - 1] - '0';
            }
        }

        Course* c = new Course(name, L, T, Lb, CLb);
        c->assignFaculty(new Faculty(prof));
        courses.push_back(c);
        courseMap[name] = c;

    }

    fin.close();

    fin.open("groups.txt", std::ifstream::in);
    fin >> n;

    for(int k = 0; k < n; k++) {
        std::string name = "";
        int sz = 0;
        fin >> name >> sz;

        Group* g = new Group(name, sz);

        std::string curr = "";

        fin.getline(input, 256);
        fin.getline(input, 256);
        for(int i = 0; i < fin.gcount(); i++) {
            if(input[i] == ',' || input[i] == '\0') {
                courseMap[curr]->enrollGroup(g);
                curr = "";
            }
            else{
                curr += input[i];
            }
        }

    }

    for(int i = 0; i < courses.size(); i++) {
        reg(courses[i], "Lab", courses[i]->Lb);
    }

    for(int i = 0; i < courses.size(); i++) {
        reg(courses[i], "CompLab", courses[i]->CLb);
    }

    for(int i = 0; i < courses.size(); i++) {
        reg(courses[i], "Lecture", courses[i]->L);
    }
    for(int i = 0; i < courses.size(); i++) {
        reg(courses[i], "Tutorial", courses[i]->T);
    }

}
