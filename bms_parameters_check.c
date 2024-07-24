#include <stdio.h>
#include <assert.h>
#include "bms_parameters_check.h"

float calculate_tolerance(float range,float tolerance)
{
    return ((range/100)*tolerance);
}

int check_min_range(float value, float range)
{
   if(value < range)
   {
       return 0;
   }
   return 1;
}

int check_max_range(float value,float range)
{
    if(value > range)
    {
        return 0;
    }
    return 1;
}

int check_low(float value,float *range_arr,char *str)
{
    if(check_min_range(value,range_arr[0]))
    {
        if(check_min_range(value,range_arr[1]))
        {
            printf("%s is in normal range\n",str);
            return 1;
        }
        printf("%s is in low range\n",str);
        return 0;
    }
    printf("%s is out of range range\n",str);
    return 0;
}

int check_high(float value,float *range_arr,char *str)
{
    if(!check_max_range(value,range_arr[2]))
    {
        if(!check_max_range(value,range_arr[3]))
        {
            printf("%s is out of range\n",str);
            return 0;
        }
        printf("%s is in high range\n",str);
        return 0;
    }
    return 1;
}

int battery_param_temp_soc(float value,float min_range,float max_range,char *str)
{
    float min_tol;
    float max_tol;
    int result;
    float range_arr[4] = {0};
    int tolerance = 5;

    range_arr[0] = min_range + calculate_tolerance(min_range,tolerance) ;
    range_arr[1] = min_range;
    range_arr[2] = max_range - calculate_tolerance(max_range,tolerance);
    range_arr[3] = max_range;

    if(check_high(value,range_arr,str))
    {
       return check_low(value,range_arr,str);
    }
    return 0;

}

int battery_charge_rate(float value,float range)
{
    float min_tole;
    int tolerance = 5;

    min_tole = range - calculate_tolerance(range,tolerance);

    if(check_max_range(value,range))
    {
        if(!check_min_range(value,min_tole))
        {
            printf(" ChargeRate is normal\n");
            return 1;
        }
        printf("ChargeRate is low range\n");
        return 1;

    }
    printf("ChargeRate is out of range\n");
    return 0;

}

int batteryIsOk(float temperature, float soc, float chargeRate) {

  int result1;
  int result2;
  int result3;

  result1 = battery_param_temp_soc(temperature,0.0,45.0,"Temperature") ;
  result2 = battery_param_temp_soc(soc,20.0,80.0,"SOC") ;
  result3 = battery_charge_rate(chargeRate,0.8);

  return result1 && result2 && result3;
}
