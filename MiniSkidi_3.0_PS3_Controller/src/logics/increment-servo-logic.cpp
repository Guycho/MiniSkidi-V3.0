/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/

#include "increment-servo-logic.h"
#include "consts.h"
#include "utils.h"

static const uint16_t MS_IN_SECOND = 1000;

void IncrementServoLogic::init(double degrees_per_second = Consts::FALLBACK_DEGREES_PER_SECOND_LOGIC)
{
  if (0 == degrees_per_second)
  {
    degrees_per_second = Consts::FALLBACK_DEGREES_PER_SECOND_LOGIC;
  }
  my_step_delay = MS_IN_SECOND / degrees_per_second;
  my_step_timer.start();
}

int8_t IncrementServoLogic::increment_servo_logic_do(bool up, bool down)
{
  int8_t step = Utils::STATIC;
  if (my_step_timer.hasPassed(my_step_delay, false) && (up != down))
  {
    if (true == up)
    {
      step = Utils::UP;
    }
    else if (true == down)
    {
      step = Utils::DOWN;
    }
    my_step_timer.restart();
  }
  return step;
}
