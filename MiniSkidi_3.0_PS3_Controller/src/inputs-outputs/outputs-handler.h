#ifndef _OUTPUTS_HANDLER_H
#define _OUTPUTS_HANDLER_H
/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/
#include <Arduino.h>
void outputs_handler_init();
void outputs_handler_run(double right_motor_pct, double left_motor_pct, double arm_motor_pct, int8_t bucket_servo_step, int8_t claw_servo_step, bool aux_lights_toggle);

#endif
