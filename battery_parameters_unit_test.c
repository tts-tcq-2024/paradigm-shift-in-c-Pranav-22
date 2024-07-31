#include "battery_parameters_unit_test.h"
#include "battery_parameters_check.h"
#include "common_util.h"
#include <assert.h>

void battery_parameters_testing(void)
{
    battery_status result = normal;
    float temp[]  = {25,50,100,0,44};
    float soc[]   = {70,85,20,15,77};
    float chg_rate[] = {0.7,0,1,0.9,0.77};

    for(int i=0;i<5;i++)
    {
        result = batteryIsOk(temp[i],soc[i],chg_rate[i]);
        if(result == error)
        {
            assert(!result);
        }
        else
        {
            assert(result);
        }

    }
}
