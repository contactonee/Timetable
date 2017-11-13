#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>



#include "Group.h"
#include "Timeslot.h"



int main() {

    Group* g = new Group("EEEY1", 60);
    std::cout << g->getAvailable() << "\n";
}
