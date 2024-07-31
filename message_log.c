#include "message_log.h"
#include "common_util.h"

void message_logger(char *str,float value, battery_status state)
{
    if(state == warning)
    {
        printf("warning: %s %f is breaching \n",str,value);
    }
    else if(state == error)
    {
        printf("Error: %s %f is out of range\n",str,value);
    }
    else
    {
        printf("No Error: %s %f is Normal\n",str,value);
    }
}
