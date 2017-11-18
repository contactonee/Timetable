#ifndef ROOM_H
#define ROOM_H

#include <string>
#include "Reservable.h"


class Room : public Reservable {
public:
    Room(std::string name,
        int size,
        bool laboratory = 0,
        bool computers = 0);

    std::string name();
    int size();
    bool compLab;
    bool lab;
private:
    std::string Name;
    int Size;
};

#endif
