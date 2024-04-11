#ifndef _ICONTROLLER_H
#define _ICONTROLLER_H

/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/

class IControllerConfig
{
private:
  virtual void foo()
  {
    return;
  }
};

class IControllerData
{
private:
  virtual void bar()
  {
    return;
  }
};

class IControllerState
{
private:
  virtual void baz()
  {
    return;
  }
};

class IController
{
public:
  virtual void init(const IControllerConfig *controller_config) = 0;
  virtual IControllerData get_controller_data() = 0;
  virtual void set_controller_state(IControllerState state) = 0;
};
#endif
