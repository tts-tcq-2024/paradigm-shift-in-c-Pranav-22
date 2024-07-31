#include "common_util.h"
#include "battery_charge_rate_checker.h"

battery_status check_battery_chargerate_warning(float value,float range)
{

    if(value > range)
    {
        return warning;
    }
    return normal;
}

battery_status check_battery_chargerate_error(float value,float range)
{

    if(value > range)
    {
        return error;
    }
    return warning;
}

battery_status battery_charge_rate(float value,float range)
{
    float min_tole;
    int tolerance = 5;
    battery_status result1 = normal;
    battery_status result2 = normal;

    min_tole = range - calculate_tolerance(range,tolerance);

    if(check_battery_chargerate_warning(value,min_tole) == warning)
    {
          return check_battery_chargerate_error(value,range);
    }

    return normal;

}
