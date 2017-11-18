#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <vector>

#include "Student.h"


class Group {
public:
    Group(std::string name, int size);

    std::string name();
    int size();

    std::vector < Student* > students;

private:
    std::string Name;
    int Size;

};

#endif // GROUP_H
