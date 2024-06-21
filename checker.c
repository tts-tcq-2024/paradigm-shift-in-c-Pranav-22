#include <stdio.h>
#include <assert.h>

int temp_range(float temperature)
{
    if(temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return 0;
  } 
  return 1;
}

int soc_range(float soc,int result)
{
    int res = 0;
   if((soc < 20 || soc > 80) )
   {
    printf("State of Charge out of range!\n");
    res= 0;
  }
    else if(result == 1)
   {
      res = 1;
   }
    return res;
}

int chargeRate_range(float chargeRate,int result)
{
    int res = 0;
  if(chargeRate > 0.8 ) {
    printf("Charge Rate out of range!\n");
    res = 0;
  }
  else if(result == 1)
  {
   res = 1;
  }
     return res;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {

  int res1 = 1;
  int res2 = 1;
  int res3 = 1;
    
  res1 = temp_range(temperature);
  res2 = soc_range(soc,res1);
  res3 = chargeRate_range(chargeRate,res2);

  return res3;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
