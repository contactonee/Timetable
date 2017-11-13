#include "Time.h"
#include <cctype>

Time::Time(int timestamp) {
    Timestamp = timestamp;
}

Time::Time(int day, int hours, int minutes, int seconds) {
    Timestamp = seconds
        + 60 * (minutes
        + 60 * (hours
        + 24 * (day - 1)));
}
Time::Time(std::string day, int hours, int minutes, int seconds) {
    Timestamp = seconds
        + 60 * (minutes
        + 60 * (hours
        + 24 * (Time::dayStringToInt(day) - 1)));
}
Time::day() {
    return (Timestamp / 60 / 60 / 24) + 1;
}
Time::hours() {
    return (Timestamp / 60 / 60) % 24;
}
Time::minutes() {
    return (Timestamp / 60) % 60;
}
Time::seconds() {
    return Timestamp % 60;
}
Time::timestamp() {
    return Timestamp;
}
int Time::dayStringToInt(std::string day) {
    char ch1 = (char)tolower((int)day[0]);
    char ch2 = (char)tolower((int)day[1]);

    if(ch1 == 'm'){
        return 1;
    }
    else if(ch1 == 't'){
        if(ch2 == 'u') {
            return 2;
        }
        else {
            return 4;
        }
    }
    else if(ch1 == 'w') {
        return 3;
    }
    else if(ch1 == 'f') {
        return 5;
    }
    else {
        if(ch2 == 'a') {
            return 6;
        }
        else return 7;
    }
}
