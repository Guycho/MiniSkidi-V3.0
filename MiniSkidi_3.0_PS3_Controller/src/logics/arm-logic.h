#ifndef _ARM_LOGIC_H
#define _ARM_LOGIC_H

/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/
#include <Arduino.h>

class ArmLogic
{
public:
  void calc_arm_motion(double y, double &arm_motor_pct);

private:
};
#endif
