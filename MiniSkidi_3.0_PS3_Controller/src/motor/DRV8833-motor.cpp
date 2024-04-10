/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/

#include "DRV8833-motor.h"

static const uint8_t MAX_UINT_DC = UINT8_MAX;
static const uint8_t MIN_UINT_DC = 0;
static const double MAX_PERCENT = 100.0;
static const double MAX_PERCENT_SCALED = 1.0;
static const double ZERO_DOUBLE = 0.0;
static const double MAX_UINT_DC_DOUBLE = MAX_UINT_DC;
static const int8_t FORWARDS = 1;
static const int8_t STOP = 0;
static const int8_t BACKWARDS = -1;

void DRV8833Motor::init(const IMotorConfig *motor_config)
{
  const DRV8833MotorConfig *my_motor_config = static_cast<const DRV8833MotorConfig *>(motor_config);
  if (my_motor_config != nullptr)
  {
    if (true == my_motor_config->reverse)
    {
      my_pwm_pin1 = my_motor_config->pwm_pin1;
      my_pwm_pin2 = my_motor_config->pwm_pin2;
    }
    else if (false == my_motor_config->reverse)
    {
      my_pwm_pin1 = my_motor_config->pwm_pin2;
      my_pwm_pin2 = my_motor_config->pwm_pin1;
    }
    my_max_percentage_dc = my_motor_config->max_percentage_dc / MAX_PERCENT;
    if (my_max_percentage_dc < ZERO_DOUBLE)
    {
      my_max_percentage_dc = (ZERO_DOUBLE);
    }
    if (my_max_percentage_dc > MAX_PERCENT_SCALED)
    {
      my_max_percentage_dc = (MAX_PERCENT_SCALED);
    }
    my_min_speed = my_motor_config->min_speed;
    my_dead_band = my_motor_config->dead_band;
    is_config_valid = true;
    off();
  }
}

void DRV8833Motor::set_speed_pct(double speed)
{
  if (false == is_config_valid)
  {
    return;
  }
  if (true == my_is_off)
  {
    pinMode(my_pwm_pin1, OUTPUT);
    pinMode(my_pwm_pin2, OUTPUT);
    my_is_off = false;
  }

  if (abs(speed) < my_dead_band)
  {
    speed = 0;
  }
  double my_corrected_speed = (abs(speed) - my_dead_band) * (MAX_PERCENT - my_min_speed) / (MAX_PERCENT - my_dead_band) + my_min_speed;
  if (speed < -MAX_PERCENT)
  {
    my_corrected_speed = (-MAX_PERCENT);
  }
  if (speed > MAX_PERCENT)
  {
    my_corrected_speed = (MAX_PERCENT);
  }
  my_dc = static_cast<uint8_t>(((abs(my_corrected_speed) / MAX_PERCENT) * MAX_UINT_DC_DOUBLE) * my_max_percentage_dc);
  my_dir = speed > ZERO_DOUBLE ? (FORWARDS) : (speed < ZERO_DOUBLE ? (BACKWARDS) : (STOP));
  run();
}

void DRV8833Motor::run()
{
  if (false == is_config_valid)
  {
    return;
  }
  if (STOP == my_dir)
  {
    analogWrite(my_pwm_pin1, my_max_dc);
    analogWrite(my_pwm_pin2, my_max_dc);
  }
  else if (FORWARDS == my_dir)
  {
    analogWrite(my_pwm_pin1, my_dc);
    analogWrite(my_pwm_pin2, MIN_UINT_DC);
  }
  else if (BACKWARDS == my_dir)
  {
    analogWrite(my_pwm_pin1, MIN_UINT_DC);
    analogWrite(my_pwm_pin2, my_dc);
  }
}

void DRV8833Motor::off()
{
  my_is_off = true;
  pinMode(my_pwm_pin1, INPUT);
  pinMode(my_pwm_pin2, INPUT);
  analogWrite(my_pwm_pin1, 0);
  analogWrite(my_pwm_pin2, 0);
}
