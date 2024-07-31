#include "common_util.h"

float calculate_tolerance(float range,float tolerance)
{
    return ((range/100)*tolerance);
}

bool check_min_range(float value, float range)
{
   if(value < range)
   {
       return true;
   }
   return false;
}

bool check_max_range(float value,float range)
{
    if(value > range)
    {
        return true;
    }
    return false;
}

battery_status check_battery_warning(float value,float *range_arr)
{
    /*Warning levels are checked*/
    if(check_min_range(value,range_arr[min_tolerance]))
    {
        return warning;
    }

    if(check_max_range(value,range_arr[max_tolerance]))
    {
        return warning;
    }
    return normal;
}

battery_status check_battery_error(float value, float *range_arr)
{
    /*Error thresholds are checked*/
    if(check_min_range(value,range_arr[min]))
    {
        return error;
    }

    if(check_max_range(value,range_arr[max]))
    {
        return error;
    }
    return warning;

}
