/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/
#include "controller/PS3-controller.h"
#include "logics/logics-handler.h"
#include "inputs-handler.h"
#include "consts.h"

void setup_controller();


void inputs_handler_init(){
  setup_controller();
}
void inputs_handler_run(){
  PS3Controller &ps3_controller = PS3Controller::getInstance();
  const PS3ControllerData *my_input_data = static_cast<const PS3ControllerData *>(ps3_controller.get_controller_data());

  logics_handler_run(my_input_data->stick_lx, my_input_data->stick_ly, my_input_data->stick_ry, my_input_data->r1, my_input_data->r2, my_input_data->r3, my_input_data->l1, my_input_data->l2);
}

void setup_controller()
{
  PS3ControllerConfig controller_config;
  controller_config.connection_string = Consts::PS3_CONTROLLER_CONNECTION_STRING;
  PS3Controller &ps3_controller = PS3Controller::getInstance();
  ps3_controller.init(&controller_config);
}
