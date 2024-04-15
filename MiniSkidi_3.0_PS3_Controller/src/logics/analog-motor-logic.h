#ifndef _ANALOG_MOTOR_LOGIC_H
#define _ANALOG_MOTOR_LOGIC_H

/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/
#include <Arduino.h>

class AnalogMotorLogic
{
public:
  void analog_motor_logic_do(double y, double &arm_motor_pct);

private:
};
#endif
