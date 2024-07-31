#include "common_util.h"
#include "battery_soc_checker.h"

battery_status battery_soc_check(float value,float min_range,float max_range)
{
    float min_tol;
    float max_tol;
    battery_status result1;
    battery_status result2;
    float range_arr[4] = {0};
    int tolerance = 5;

    range_arr[min_tolerance] = min_range + calculate_tolerance(min_range,tolerance) ;
    range_arr[min] = min_range;
    range_arr[max_tolerance] = max_range - calculate_tolerance(max_range,tolerance);
    range_arr[max] = max_range;

     if(check_battery_warning(value,range_arr)== warning)
     {
         return check_battery_error(value,range_arr);
     }

     return normal;
}
