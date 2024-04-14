/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/
#include "logics-handler.h"
#include "arm-logic.h"
#include "bucket-logic.h"
#include "claw-logic.h"
#include "diff-drive-logic.h"
#include "aux-lights-logic.h"
#include "inputs-outputs\outputs-handler.h"
#include "consts.h"

ArmLogic arm_logic;
DiffDriveLogic diff_drive_logic;
BucketLogic bucket_logic;
ClawLogic claw_logic;
AuxLightsLogic aux_lights_logic;

/*
motion LX + LY
arm RY
aux lights R3
bucket up r2 down l2
claw up r1 down l1
*/

void logics_handler_init()
{
  bucket_logic.init(Consts::BUCKET_LOGIC_DEGREES_PER_SECOND);
  claw_logic.init(Consts::CLAW_LOGIC_DEGREES_PER_SECOND);
}
void logics_handler_run(double lx, double ly, double ry, bool r1, bool r2, bool r3, bool l1, bool l2)
{
  double arm_pct = 0;
  double right_pct = 0;
  double left_pct = 0;
  arm_logic.calc_arm_motion(ry, arm_pct);
  diff_drive_logic.calc_diff_drive(ly, ry, right_pct, left_pct);
  int8_t bucket_step = bucket_logic.calc_bucket_motion(r2, l2);
  int8_t claw_step = claw_logic.calc_claw_motion(r1, l1);
  bool aux_lights_toggle = aux_lights_logic.aux_lights_logic_run(r3);
  outputs_handler_run(right_pct, left_pct, arm_pct, bucket_step, claw_step, aux_lights_toggle);
}
