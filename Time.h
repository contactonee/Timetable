#ifndef TIME_H
#define TIME_H

#include <string>

class Time {
public:
    Time(int timestamp = 0);
    Time(int day,
        int hours,
        int minutes = 0,
        int seconds = 0);

    Time(std::string day,
        int hours,
        int minutes = 0,
        int seconds = 0);

    int getDay();
    int getHours();
    int getMinutes();
    int getSeconds();
    int getTimestamp();

    static int dayStringToInt(std::string day);


private:
    int timestamp = 0;

};

#endif
