/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/

#include <Ps3Controller.h>
#include "PS3-controller.h"
#include "utils.h"

const double MAX_ANALOG_VALUE = 100.00;

void PS3Controller::init(const IControllerConfig *controller_config)
{
  const PS3ControllerConfig *Ps3_config = static_cast<const PS3ControllerConfig *>(controller_config);
  if (Ps3_config != nullptr)
  {
    config_is_valid = true;
    const char *my_connection_string = Ps3_config->connection_string.c_str();
    Ps3.begin(my_connection_string);
  }
  if (false == config_is_valid)
  {
    return;
  }
  Ps3.attach(PS3Controller::run);
  Ps3.attachOnConnect(on_connect);
}
IControllerData PS3Controller::get_controller_data() {
  return ps_controller_data;
}
void PS3Controller::set_controller_state(IControllerState state) {
  
}

void PS3Controller::run()
{
  PS3Controller &my_controller = PS3Controller::getInstance();
  my_controller.ps_controller_data.stick_lx = Utils::map_double(Ps3.data.analog.stick.lx, INT8_MIN, INT8_MAX, -MAX_ANALOG_VALUE, MAX_ANALOG_VALUE);
  my_controller.ps_controller_data.stick_ly = Utils::map_double(Ps3.data.analog.stick.ly, INT8_MIN, INT8_MAX, -MAX_ANALOG_VALUE, MAX_ANALOG_VALUE);
  my_controller.ps_controller_data.stick_rx = Utils::map_double(Ps3.data.analog.stick.rx, INT8_MIN, INT8_MAX, -MAX_ANALOG_VALUE, MAX_ANALOG_VALUE);
  my_controller.ps_controller_data.stick_ry = Utils::map_double(Ps3.data.analog.stick.ry, INT8_MIN, INT8_MAX, -MAX_ANALOG_VALUE, MAX_ANALOG_VALUE);
  my_controller.ps_controller_data.r1 = Ps3.event.button_down.r1;
  my_controller.ps_controller_data.r2 = Ps3.event.button_down.r2;
  my_controller.ps_controller_data.r3 = Ps3.event.button_down.r3;
  my_controller.ps_controller_data.l1 = Ps3.event.button_down.l1;
  my_controller.ps_controller_data.l2 = Ps3.event.button_down.l2;
  my_controller.ps_controller_data.l3 = Ps3.event.button_down.l3;
}

void PS3Controller::on_connect()
{
}
