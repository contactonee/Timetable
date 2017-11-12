#ifndef GROUP_H
#define GROUP_H

#include <string>

#include "Reservable.h"

class Group : public Reservable {
public:
    Group(std::string name, int size);
    std::string name;
    int size;

};

#endif // GROUP_H
