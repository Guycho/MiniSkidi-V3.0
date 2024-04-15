#include "inputs-outputs/outputs-handler.h"
#include "inputs-outputs/inputs-handler.h"
#include "logics/logics-handler.h"

void setup()
{
  inputs_handler_init();
  outputs_handler_init();
  logics_handler_init();
}

void loop()
{
  inputs_handler_run();
}
