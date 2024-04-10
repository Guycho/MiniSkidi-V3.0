/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/

#include "ppm-servo.h"

void PpmServo::init(const IServoConfig *servo_config)
{
  const PpmServoConfig *my_servo_config = static_cast<const PpmServoConfig *>(servo_config);
  if (my_servo_config != nullptr)
  {
    my_ppm_pin = my_servo_config->ppm_pin;
    is_config_valid = true;
  }
}

void PpmServo::step(bool dir)
{
  my_pos = true == dir ? my_pos + my_step_size : my_pos - my_step_size;

}

PpmServo::set_pos(uint8_t angle){
  
}
