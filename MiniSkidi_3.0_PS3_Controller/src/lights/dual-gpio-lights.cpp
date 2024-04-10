/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/

#include "dual-gpio-lights.h"

void DualGpioLights::init(const ILightsConfig *lights_config)
{
  const DualGpioLightsConfig *my_lights_config = static_cast<const DualGpioLightsConfig *>(lights_config);
  if (my_lights_config != nullptr)
  {
    my_positive_pin = my_lights_config->positive_pin;
    my_negative_pin = my_lights_config->negative_pin;
    my_state = my_lights_config->init_state;
    is_config_valid = true;
  }
  if (false == is_config_valid)
  {
    return;
  }
  set_state(my_state);
  }

void DualGpioLights::toggle()
{
  if (false == is_config_valid)
  {
    return;
  }
  my_state = !my_state;
  set_state(my_state);
}

void DualGpioLights::set_state(bool state)
{
  if (false == is_config_valid)
  {
    return;
  }
  if (true == state)
  {
    digitalWrite(my_positive_pin, HIGH);
    digitalWrite(my_negative_pin, LOW);
  }
  else if (false == state)
  {
    digitalWrite(my_positive_pin, LOW);
    digitalWrite(my_negative_pin, LOW);
  }
}
