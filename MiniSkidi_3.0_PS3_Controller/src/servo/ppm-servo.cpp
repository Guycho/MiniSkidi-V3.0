/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/

#include "ppm-servo.h"
#include "utils.h"

static uint8_t SERVO_ABSOLUTE_MAX_VALUE = 180;
static uint8_t SERVO_ABSOLUTE_MIN_VALUE = 0;

void PpmServo::init(const IServoConfig *servo_config)
{
  const PpmServoConfig *my_servo_config = static_cast<const PpmServoConfig *>(servo_config);
  if (my_servo_config != nullptr)
  {
    pinMode(my_servo_config->ppm_pin, OUTPUT);
    is_config_valid = true;
    my_servo.attach(my_servo_config->ppm_pin);
    my_pos = my_servo_config->init_pos;
    my_min_pos = my_servo_config->min_pos;
    my_max_pos = my_servo_config->max_pos;
    my_reverse = my_servo_config->reverse;
    is_config_valid = true;
  }
  if (true == is_config_valid){
    set_pos(my_pos);
  }
}

void PpmServo::step(int8_t dir)
{
  my_pos = Utils::UP == dir ? my_pos + my_step_size : Utils::DOWN == dir ? my_pos - my_step_size
                                                                         : my_pos;
  my_pos = constrain(my_pos, my_min_pos, my_max_pos);
  set_pos(my_pos);
}

void PpmServo::set_pos(uint8_t angle){
  if (false == is_config_valid){
    return;
  }
  angle = constrain(angle, SERVO_ABSOLUTE_MIN_VALUE, SERVO_ABSOLUTE_MAX_VALUE);
  if (false == my_reverse)
  {
    my_servo.write(angle);
  }
  else if (false == my_reverse)
  {
    my_servo.write(SERVO_ABSOLUTE_MAX_VALUE - angle);
  }
}
