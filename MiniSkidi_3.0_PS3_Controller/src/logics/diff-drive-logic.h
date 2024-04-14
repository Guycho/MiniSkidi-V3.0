#ifndef _DIFF_DRIVE_MIXER_H
#define _DIFF_DRIVE_MIXER_H

/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/
#include <Arduino.h>

class DiffDriveLogic
{
public:
  void calc_diff_drive(double y, double x, double &right_motor_pct, double &left_motor_pct);

private:
};
#endif
