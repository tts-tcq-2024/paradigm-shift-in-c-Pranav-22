#include "battery_temperature_checker.h"
#include "battery_soc_checker.h"
#include "battery_charge_rate_checker.h"
#include "message_log.h"
#include "common_util.h"

int batteryIsOk(float temperature, float soc, float chargeRate)
{

  battery_status result1 = normal;
  battery_status result2 = normal;
  battery_status result3 = normal;

  result1 = battery_temperature_check(temperature,0.0,45.0);
  message_logger("Temperature",temperature,result1);

  result2 = battery_soc_check(soc,20.0,80.0) ;
  message_logger("SOC",soc,result2);

  result3 = battery_charge_rate(chargeRate,0.8);
  message_logger("Charge Rate",chargeRate,result3);

  return result1 && result2 && result3;
}
