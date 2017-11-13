#include "Group.h"

Group::Group(std::string name, int size, Group* parent) {
    Name = name;
    Size = size;
    Parent = parent;

    InitSlots();

}

std::string Group::name() {
    return Name;
}

int Group::size() {
    return Size;
}

void Group::reserve(int k) {
    reserve(this, k);
}

void Group::reserve(Group* group, int k) {

    if(group != NULL) {
        group->slots[k]->available = 0;

    }

}
