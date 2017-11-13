#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <vector>

#include "Reservable.h"

class Group : public Reservable {
public:
    Group(std::string name, int size, Group* parent = NULL);

    std::string name();
    int size();


private:
    std::string Name;
    int Size;
    Group* Parent;

    vector < Group* > Subgroups;

};

#endif // GROUP_H
