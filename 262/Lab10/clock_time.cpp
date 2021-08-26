//
// Created by Eli Billinger on 11/9/20.
//

#include "clock_time.h"

clock_time::clock_time() {
    _seconds = 0;
}

clock_time::clock_time(int h, int m, int s) {
    set_time(h,m,s);
}

int clock_time::get_hour() {
    int hours = _seconds / 3600;
    hours = hours % 24;
    if(hours < 0){
        hours = hours + 23;
    }
    return hours;
}

int clock_time::get_minute() {
    int minutes = (_seconds % 3600) / 60;
    if(minutes < 0){
        minutes += 59;
    }
    return minutes;
}

int clock_time::get_second() {
    int secounds = (_seconds % 60);
    if(secounds < 0){
        secounds += 60;
    }
    return secounds;
}

void clock_time::set_time(int h, int m, int s) {
    _seconds = (h*3600) + (m * 60) + s;
}

string to_string(clock_time c){
    string time = "";
    string h,m,s;
    int hour = c.get_hour();
    h = to_string(hour);
    time += h;
    time += ":";
    int min = c.get_minute();
    if(min < 10){
        m = "0" + to_string(min);
    } else {
        m = to_string(min);
    }
    time += m;
    time += ":";
    int sec = c.get_second();
    if(sec < 10){
        s = "0" + to_string(sec);
    } else {
        s = to_string(sec);
    }
    time += s;
    return time;
}

ostream& operator<<(ostream & out, clock_time c){
    string time = to_string(c);
    out << time;
    return out;
}

bool operator==(clock_time a, clock_time b) {
    int a_hour = 3600*a.get_hour();
    int a_min = 60*a.get_minute();
    int a_sec = a.get_second();
    int b_hour = 3600*b.get_hour();
    int b_min = 60*b.get_minute();
    int b_sec = b.get_second();
    if(a_hour == b_hour && a_min == b_min && a_sec == b_sec){
        return true;
    } else{
        return false;
    }
}

bool operator!=(clock_time a, clock_time b) {
    int a_hour = 3600*a.get_hour();
    int a_min = 60*a.get_minute();
    int a_sec = a.get_second();
    int b_hour = 3600*b.get_hour();
    int b_min = 60*b.get_minute();
    int b_sec = b.get_second();
    if(a_hour == b_hour && a_min == b_min && a_sec == b_sec){
        return false;
    } else{
        return true;
    }
}
 clock_time operator+(clock_time a, clock_time b) {
     return clock_time(a.get_hour()+b.get_hour(),a.get_minute()+b.get_minute(),a.get_second()+b.get_second());
}
