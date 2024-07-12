#include <stdio.h>
#include <assert.h>

int chargeRate_range(float chargeRate)
{
  if(chargeRate > 0.8 ) {
    printf("Charge Rate out of range!\n");
    return 0;
  }
     return 1;
}

int soc_range(float soc)
{
    int result = 0;
   if(soc > 80)
   {
    printf("State of Charge out of range!\n");
    return 0;
   }

    return 1;
}

int temp_range(float temperature)
{
    int result = 0;
    
    if(temperature > 45) {
    printf("Temperature out of range!\n");
    return 0;
  } 

    return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {

  int result = 1;
   
 return temp_range(temperature) && soc_range(soc) && chargeRate_range(chargeRate);

  return result;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
