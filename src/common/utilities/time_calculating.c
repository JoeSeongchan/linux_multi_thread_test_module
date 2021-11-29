//
// Created by seongchan-joe on 21. 10. 28..
//

#include "time_calculating.h"

unsigned long long calclock3(struct timespec64 *spclock) {
    long temp, temp_n;
    unsigned long long time_delay = 0;
    if (spclock[1].tv_nsec >= spclock[0].tv_nsec) {
        temp = spclock[1].tv_sec - spclock[0].tv_sec;
        temp_n = spclock[1].tv_nsec = spclock[0].tv_nsec;
        time_delay = BILLION * temp + temp_n;
    } else {
        temp = spclock[1].tv_sec - spclock[0].tv_sec - 1;
        temp_n = BILLION + spclock[1].tv_nsec - spclock[0].tv_nsec;
        time_delay = BILLION * temp + temp_n;
    }
    return time_delay;
}
