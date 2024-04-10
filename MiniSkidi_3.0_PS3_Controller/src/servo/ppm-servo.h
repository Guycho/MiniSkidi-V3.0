#ifndef _PPM_SERVO_H
#define _PPM_SERVO_H

/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/

#include <Arduino.h>
#include <ESP32Servo.h> // by Kevin Harrington
#include "iservo.h"

class PpmServoConfig : public IServoConfig
{
public:
  uint8_t ppm_pin;
  uint8_t init_pos;
  uint8_t min_pos;
  uint8_t max_pos;
  uint8_t step_size;
  bool reverse;
};

class PpmServo : public IServo
{
public:
  void init(const IServoConfig *servo_config) override;
  void step(bool dir) override;


private:
  void set_pos(uint8_t angle);
  uint8_t my_pos = -1;
  uint8_t my_ppm_pin = -1;
  uint8_t my_init_pos = -1;
  uint8_t my_min_pos = -1;
  uint8_t my_max_pos = -1;
  uint8_t my_step_size = -1;
  bool my_reverse = false;
  bool is_config_valid = false;
};
#endif
