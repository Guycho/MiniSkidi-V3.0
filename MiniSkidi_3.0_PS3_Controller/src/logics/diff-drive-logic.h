#ifndef _DIFF_DRIVE_LOGIC_H
#define _DIFF_DRIVE_LOGIC_H

/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/
#include <Arduino.h>

class DiffDriveLogic
{
public:
  void diff_drive_logic_do(double y, double x, double &right_motor_pct, double &left_motor_pct);

private:
};
#endif
