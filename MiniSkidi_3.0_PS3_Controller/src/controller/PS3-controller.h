#ifndef _PS3_CONTROLLER_H
#define _PS3_CONTROLLER_H

/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/

#include <Arduino.h>
#include "icontroller.h"

class PS3ControllerConfig : public IControllerConfig
{
public:
  String connection_string;
};

class PS3ControllerData : public IControllerData
{
public:
  double stick_ly = 0;
  double stick_lx = 0;
  double stick_ry = 0;
  double stick_rx = 0;
  bool r1 = false;
  bool r2 = false;
  bool r3 = false;
  bool l1 = false;
  bool l2 = false;
  bool l3 = false;
};

class PS3ControllerState : public IControllerState
{
public:
};

class PS3Controller : public IController
{
public:
  static PS3Controller &getInstance()
  {
    static PS3Controller instance; // Guaranteed to be destroyed.
                                   // Instantiated on first use.
    return instance;
  }
  void init(const IControllerConfig *controller_config) override;
  IControllerData *get_controller_data() override;
  void set_controller_state(IControllerState state) override;
  static void run();
  static void on_connect();
  PS3ControllerData ps_controller_data;
  uint8_t battery_state;

private:
  PS3Controller() {}
  PS3Controller(const PS3Controller &);
  bool config_is_valid = false;
};
#endif
