/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/

#include "analog-motor-logic.h"
#include "utils.h"

static const double MAX_PERCENT = 100.0;

void AnalogMotorLogic::analog_motor_logic_do(double y, double &arm_motor_pct)
{
  arm_motor_pct = y;
  Utils::constrain_double(arm_motor_pct, -MAX_PERCENT, MAX_PERCENT);
}
