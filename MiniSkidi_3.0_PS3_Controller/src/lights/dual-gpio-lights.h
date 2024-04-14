#ifndef _DUAL_GPIO_LIGHTS_H
#define _DUAL_GPIO_LIGHTS_H

/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/

#include <Arduino.h>
#include "ilights.h"

class DualGpioLightsConfig : public ILightsConfig
{
public:
  uint8_t positive_pin;
  uint8_t negative_pin;
  bool init_state;
};

class DualGpioLights : public ILights
{
public:
  void init(const ILightsConfig *lights_config) override;
  void toggle(bool toggle) override;

private:
  void set_state(bool state);
  uint8_t my_positive_pin = -1;
  uint8_t my_negative_pin = -1;
  bool my_state = false;
  bool is_config_valid = false;
};
#endif
