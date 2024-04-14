#include "inputs-outputs/outputs-handler.h"
#include "inputs-outputs/inputs-handler.h"

void setup()
{
  inputs_handler_init();
  outputs_handler_init();
}

void loop()
{
  inputs_handler_run();
}
