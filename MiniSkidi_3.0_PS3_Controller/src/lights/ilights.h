#ifndef _ILIGHTS_H
#define _ILIGHTS_H

/**************************************************************************************************************

  Created : Guy Raiz

******************************************************************************************************************/

class ILightsConfig
{
private:
  virtual void foo()
  {
    return;
  }
};

class ILights
{
public:
  virtual void init(const ILightsConfig *lights_config) = 0;
  virtual void toggle() = 0;
};
#endif
