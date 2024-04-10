#ifndef _ISERVO_H
#define _ISERVO_H

/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/

class IServoConfig
{
private:
  virtual void foo()
  {
    return;
  }
};

class IServo
{
public:
  virtual void init(const IServoConfig *servo_config) = 0;
  virtual void step(bool dir) = 0;
};
#endif
