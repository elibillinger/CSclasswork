//
// Created by Eli Billinger on 11/23/20.
//

#ifndef LAB12_ANALOG_CLOCK_H
#define LAB12_ANALOG_CLOCK_H

#endif //LAB12_ANALOG_CLOCK_H

using namespace std;
class analog_clock : public unix_clock{
public:
    string amPM;
    analog_clock(unix_clock c) : unix_clock(c) {
        amPM = "am";
    };

    string get_time() { string result;

        // Add correct padding
        if (get_hour() < 10 && get_hour() > 0) {
            result += "0";
            result += to_string(get_hour()) + ":";
        }
        if (get_hour() > 12){
            amPM ="pm";
            result += "0";
            result += to_string(get_hour()-12) + ":";
        }
        if (get_hour() == 12){
            amPM ="pm";
            result += to_string(get_hour()) + ":";
        }
        if(get_hour() == 0){
            result += to_string(12) + ":";
        }



        if (get_minute() < 10) {
            result += "0";
        }

        result += to_string(get_minute()) + ":";

        if (get_second() < 10) {
            result += "0";
        }

        result += to_string(get_second());

        return result + " " + amPM; }

};