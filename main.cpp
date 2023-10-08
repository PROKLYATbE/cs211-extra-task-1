#include "extra-task-1.h"

#include <assert.h>
#include <iostream>

int main() {
    double eps = 0.0001;

    // test seconds_difference
    assert(seconds_difference(1800.0, 3600.0) - 1800.0 < eps);
    assert(seconds_difference(3600.0, 1800.0) - -1800.0 < eps);
    assert(seconds_difference(1800.0, 2160.0) - 360.0 < eps);
    assert(seconds_difference(1800.0, 1800.0) - 0.0 < eps);

    // test hours_difference
    assert(hours_difference(1800.0, 3600.0) - 0.5 < eps);
    assert(hours_difference(3600.0, 1800.0) - -0.5 < eps);
    assert(hours_difference(0.0, 7200.0) - 2 < eps);

    // test to_float_hours
    assert(to_float_hours(0, 15, 0) - 0.25 < eps);
    assert(to_float_hours(2, 45, 9) - 2.7525 < eps);
    assert(to_float_hours(1, 0, 36) - 1.01 < eps);

    // test to_24_hour_clock
    assert(to_24_hour_clock(24) - 0 < eps);
    assert(to_24_hour_clock(48) - 0 < eps);
    assert(to_24_hour_clock(25) - 1 < eps);
    assert(to_24_hour_clock(4) - 4 < eps);
    assert(to_24_hour_clock(28.5) - 4.5 < eps);

    // test get_hours
    assert(get_hours(3800) == 1);

    // test get_minutes
    assert(get_minutes(3800) == 3);

    // test get_seconds
    assert(get_seconds(3800) == 20);

    // test time_to_utc
    assert(time_to_utc(+0, 12.0) - 12.0 < eps);
    assert(time_to_utc(+1, 12.0) - 11.0 < eps);
    assert(time_to_utc(-1, 12.0) - 13.0 < eps);
    assert(time_to_utc(-11, 18.0) - 5.0 < eps);
    assert(time_to_utc(-1, 0.0) - 1.0 < eps);
    assert(time_to_utc(-1, 23.0) - 0.0 < eps);
    assert(time_to_utc(+1, 0.0) - 23.0 < eps);
    assert(time_to_utc(+47, 0.0) - 1.0 < eps);

    // test time_from_utc
    assert(time_from_utc(+0, 12.0) - 12.0 < eps);
    assert(time_from_utc(+1, 12.0) - 13.0 < eps);
    assert(time_from_utc(+6, 6.0) - 12.0 < eps);
    assert(time_from_utc(-7, 6.0) - 23.0 < eps);
    assert(time_from_utc(-1, 12.0) - 11.0 < eps);
    assert(time_from_utc(-1, 0.0) - 23.0 < eps);
    assert(time_from_utc(-1, 23.0) - 22.0 < eps);
    assert(time_from_utc(+1, 23.0) - 0.0 < eps);
}