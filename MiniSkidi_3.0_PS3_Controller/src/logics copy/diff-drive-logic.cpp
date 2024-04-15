/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/

#include "diff-drive-logic.h"
#include "utils.h"
static const double MAX_PERCENT = 100.0;

void DiffDriveLogic::diff_drive_logic_do(double y, double x, double &right_motor_pct, double &left_motor_pct)
{
    right_motor_pct = y + x;
    left_motor_pct = y - x;
    Utils::constrain_double(right_motor_pct, -MAX_PERCENT, MAX_PERCENT);
    Utils::constrain_double(left_motor_pct, -MAX_PERCENT, MAX_PERCENT);
}
