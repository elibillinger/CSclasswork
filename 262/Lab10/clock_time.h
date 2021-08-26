//
// Created by Eli Billinger on 11/9/20.
//

#ifndef LAB10_CLOCK_TIME_H
#define LAB10_CLOCK_TIME_H


#include <string>
using namespace std;


class clock_time {

public:
    friend clock_time operator+(clock_time a, clock_time b); //could not figure out how to use friend prototype
    int get_hour();
    int get_minute();
    int get_second();
    void set_time(int h, int m, int s);
    clock_time();
    clock_time(int h, int m, int s);

private:
    int _seconds;
};

string to_string(clock_time c);
ostream& operator<<(ostream & out, clock_time c);
bool operator==(clock_time a, clock_time b);
bool operator!=(clock_time a, clock_time b);


#endif //LAB10_CLOCK_TIME_H
