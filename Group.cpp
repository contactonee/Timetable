#include "Group.h"

Group::Group(std::string name, int size) {
    Name = name;
    Size = size;
    for(int i = 0; i < size; i++) {
        students.push_back(new Student());
    }
}

std::string Group::name() {
    return Name;
}

int Group::size() {
    return Size;
}
