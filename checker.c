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

int soc_range(float soc,float chargeRate)
{
    int result = 1;
   if((soc < 20 || soc > 80) )
   {
    printf("State of Charge out of range!\n");
    return 0;
  }
   result = chargeRate_range(chargeRate);

    return result;
}

int temp_range(float temperature, float soc, float chargeRate)
{
    int result = 1;
    
    if(temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return 0;
  } 
    result = soc_range(soc,chargeRate);

    return result;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {

  int result = 1;
   
  result = temp_range(temperature,soc,chargeRate);

  return result;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
