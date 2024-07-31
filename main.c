#include "battery_parameters_check.h"
#include <assert.h>

int main()
{
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(100,20,1));
  assert(!batteryIsOk(0,15,0.9));
  
}
