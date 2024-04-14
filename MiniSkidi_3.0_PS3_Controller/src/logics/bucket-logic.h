#ifndef _BUCKET_LOGIC_H
#define _BUCKET_LOGIC_H

/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/
#include <Arduino.h>
#include <Chrono.h>

class BucketLogic
{
public:
  void init(double degrees_per_second);
  int8_t calc_bucket_motion(bool up, bool down);

private:
  uint32_t my_step_delay;
  Chrono my_step_timer;
};
#endif
