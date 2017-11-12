#ifndef ROOM_H
#define ROOM_H

#include <string>
#include "Reservable.h"


class Room : public Reservable {
public:
    Room(std::string title,
        int size,
        bool laboratory = 0,
        bool computers = 0);

    std::string getTitle();
    int getSize();
    bool compLab;
    bool lab;
private:
    std::string title;
    int size;
};

#endif
