#ifndef _INCREMENT_SERVO_LOGIC_H
#define _INCREMENT_SERVO_LOGIC_H

/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/
#include <Arduino.h>
#include <Chrono.h>

class IncrementServoLogic
{
public:
  void init(double degrees_per_second);
  int8_t increment_servo_logic_do(bool up, bool down);

private:
  uint32_t my_step_delay;
  Chrono my_step_timer;
};
#endif
