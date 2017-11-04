#include "Time.h"
#include <cctype>

Time::Time(int timestamp) {
    Time::timestamp = timestamp;
}
Time::Time(int day, int hours, int minutes, int seconds) {
    timestamp = seconds + 60 * (minutes + 60 * (hours + 24 * (day - 1)));
}
Time::Time(std::string day, int hours, int minutes, int seconds) {
    timestamp = seconds + 60 * (minutes + 60 * (hours + 24 * (dayToInt(day) - 1)));
}
Time::getDay() {
    return (timestamp / 60 / 60 / 24) + 1;
}
Time::getHours() {
    return (timestamp / 60 / 60) % 24;
}
Time::getMinutes() {
    return (timestamp / 60) % 60;
}
Time::getSeconds() {
    return timestamp % 60;
}
Time::getTimestamp() {
    return timestamp;
}
Time::dayToInt(std::string day) {
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
