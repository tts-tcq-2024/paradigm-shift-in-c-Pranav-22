#ifndef COMMON_UTIL_H
#define COMMON_UTIL_H

#include<stdio.h>
#include <stdbool.h>

#define    min_tolerance  0
#define    min            1
#define    max_tolerance  2
#define    max            3

typedef enum
{
    error = 0,
    warning,
    normal
}battery_status;

float calculate_tolerance(float range,float tolerance);
bool check_min_range(float value, float range);
bool check_max_range(float value,float range);
battery_status check_battery_warning(float value,float *range_arr);
battery_status check_battery_error(float value, float *range_arr);

#endif
