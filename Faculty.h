#ifndef FACULTY_H
#define FACULTY_H

#include <string>

#include "Reservable.h"


class Faculty : public Reservable{
public:
    Faculty(std::string name);
    std::string name;
};

#endif // FACULTY_H
