#ifndef _IMOTOR_H
#define _IMOTOR_H

/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/

class IMotorConfig
{
private:
  virtual void foo()
  {
    return;
  }
};

class IMotor
{
public:
  virtual void init(const IMotorConfig *motor_config) = 0;
  virtual void set_speed_pct(double speed) = 0;
  virtual void off() = 0;
};
#endif
