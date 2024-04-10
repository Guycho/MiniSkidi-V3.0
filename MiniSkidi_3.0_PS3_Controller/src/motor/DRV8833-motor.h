#ifndef _DRV8833_MOTOR_H
#define _DRV8833_MOTOR_H

/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/

#include <Arduino.h>
#include "imotor.h"

class DRV8833MotorConfig : public IMotorConfig
{
public:
  uint8_t pwm_pin1;
  uint8_t pwm_pin2;
  double max_percentage_dc;
  double min_speed;
  double dead_band;
  bool reverse;
};

class DRV8833Motor : public IMotor
{
public:
  void init(const IMotorConfig *motor_config) override;
  void set_speed_pct(double speed) override;
  void off() override;

private:
  void run();
  uint8_t my_pwm_pin1 = -1;
  uint8_t my_pwm_pin2 = -1;
  double my_max_percentage_dc = 0.0;
  uint8_t my_max_dc = 0.0;
  uint8_t my_dc = 0;
  int8_t my_dir = 0;
  double my_min_speed = 0;
  double my_dead_band = 0;
  bool my_is_off = false;
  bool is_config_valid = false;
};
#endif
