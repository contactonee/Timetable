#ifndef TIME_H
#define TIME_H

#include <string>

class Time {
public:
    Time(int timestamp);

    Time(int day,
        int hours,
        int minutes = 0,
        int seconds = 0);

    Time(std::string day,
        int hours,
        int minutes = 0,
        int seconds = 0);

    int day();
    int hours();
    int minutes();
    int seconds();
    int timestamp();

    static int dayStringToInt(std::string day);

private:
    int Timestamp = 0;

};

#endif
