#include "extra-task-1.h"

#include <cmath>
#include <assert.h>

double seconds_difference(double time_1, double time_2) {
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2) {
    return seconds_difference(time_1, time_2) / 3600;
}

double to_float_hours(int hours, int minutes, int seconds) {
    assert(minutes < 60 && minutes >= 0);
    assert(seconds < 60 && seconds >= 0);
    
    return hours + (minutes / 60.0) + (seconds / 3600.0);
}

double to_24_hour_clock(double hours) {
    assert(hours >= 0);

    while (hours >= 24)
        hours -= 24;

    return hours;
}

int get_hours(int seconds) {
    return (seconds / 3600) % 24;
}

int get_minutes(int seconds) {
    return (seconds / 60) % 60;
}

int get_seconds(int seconds) {
    return seconds % 60;
}

double time_to_utc(int utc_offset, double time) {
    assert(time >= 0 && time < 24);

    double t = time - utc_offset;
    if (t > 0)
        return to_24_hour_clock(t);
    else
        return to_24_hour_clock(24 - to_24_hour_clock(abs(t)));
}

double time_from_utc(int utc_offset, double time) {
    return time_to_utc(-utc_offset, time);
}
