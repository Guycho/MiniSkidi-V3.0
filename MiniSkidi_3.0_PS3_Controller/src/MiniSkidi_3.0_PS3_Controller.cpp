#include "motor/DRV8833-motor.h"
#include "lights/dual-gpio-lights.h"
#include "servo/ppm-servo.h"
#include "controller/PS3-controller.h"
#include "consts.h"

/*
motion LX + LY
arm RY
aux lights R3
bucket up r2 down l2
claw up r1 down l1
*/

void setup_motors();
void setup_servos();
void setup_lights();
void setup_controller();

DRV8833Motor right_motor;
DRV8833Motor left_motor;
DRV8833Motor arm_motor;

PpmServo bucket_servo;
PpmServo claw_servo;

DualGpioLights aux_lights;


void setup_motors()
{

  DRV8833MotorConfig right_motor_config;
  right_motor_config.pwm_pin1 = Consts::RIGHT_MOTOR_PWM_PIN_1;
  right_motor_config.pwm_pin2 = Consts::RIGHT_MOTOR_PWM_PIN_2;
  right_motor_config.max_percentage_dc = Consts::RIGHT_MOTOR_MAX_PERCENTAGE_DC;
  right_motor_config.min_speed = Consts::RIGHT_MOTOR_MIN_SPEED;
  right_motor_config.dead_band = Consts::RIGHT_MOTOR_DEAD_BAND;
  right_motor_config.reverse = Consts::RIGHT_MOTOR_REVERSE;
  right_motor.init(&right_motor_config);

  DRV8833MotorConfig left_motor_config;
  left_motor_config.pwm_pin1 = Consts::LEFT_MOTOR_PWM_PIN_1;
  left_motor_config.pwm_pin2 = Consts::LEFT_MOTOR_PWM_PIN_2;
  left_motor_config.max_percentage_dc = Consts::LEFT_MOTOR_MAX_PERCENTAGE_DC;
  left_motor_config.min_speed = Consts::LEFT_MOTOR_MIN_SPEED;
  left_motor_config.dead_band = Consts::LEFT_MOTOR_DEAD_BAND;
  left_motor_config.reverse = Consts::LEFT_MOTOR_REVERSE;
  left_motor.init(&left_motor_config);

  DRV8833MotorConfig arm_motor_config;
  arm_motor_config.pwm_pin1 = Consts::ARM_MOTOR_PWM_PIN_1;
  arm_motor_config.pwm_pin2 = Consts::ARM_MOTOR_PWM_PIN_2;
  arm_motor_config.max_percentage_dc = Consts::ARM_MOTOR_MAX_PERCENTAGE_DC;
  arm_motor_config.min_speed = Consts::ARM_MOTOR_MIN_SPEED;
  arm_motor_config.dead_band = Consts::ARM_MOTOR_DEAD_BAND;
  arm_motor_config.reverse = Consts::ARM_MOTOR_REVERSE;
  arm_motor.init(&arm_motor_config);
}

void setup_servos()
{
  PpmServoConfig bucket_servo_config;
  bucket_servo_config.ppm_pin = Consts::BUCKET_SERVO_PPM_PIN;
  bucket_servo_config.init_pos = Consts::BUCKET_SERVO_INIT_POS;
  bucket_servo_config.min_pos = Consts::BUCKET_SERVO_MIN_POS;
  bucket_servo_config.max_pos = Consts::BUCKET_SERVO_MIN_POS;
  bucket_servo_config.step_size = Consts::BUCKET_SERVO_STEP_SIZE;
  bucket_servo_config.reverse = Consts::BUCKET_SERVO_REVERSE;
  bucket_servo.init(&bucket_servo_config);

  PpmServoConfig claw_servo_config;
  claw_servo_config.ppm_pin = Consts::CLAW_SERVO_PPM_PIN;
  claw_servo_config.init_pos = Consts::CLAW_SERVO_INIT_POS;
  claw_servo_config.min_pos = Consts::CLAW_SERVO_MIN_POS;
  claw_servo_config.max_pos = Consts::CLAW_SERVO_MIN_POS;
  claw_servo_config.step_size = Consts::CLAW_SERVO_STEP_SIZE;
  claw_servo_config.reverse = Consts::CLAW_SERVO_REVERSE;
  claw_servo.init(&claw_servo_config);
}

void setup_lights()
{
  DualGpioLightsConfig aux_lights_config;
  aux_lights_config.positive_pin = Consts::AUX_LIGHTS_POSITIVE_PIN;
  aux_lights_config.negative_pin = Consts::AUX_LIGHTS_NEGATIVE_PIN;
  aux_lights_config.init_state = Consts::AUX_LIGHT_INIT_STATE;
  aux_lights.init(&aux_lights_config);
}

void setup_controller(){
  PS3ControllerConfig controller_config;
  controller_config.connection_string = Consts::PS3_CONTROLLER_CONNECTION_STRING;
  PS3Controller &ps3_controller = PS3Controller::getInstance();
  ps3_controller.init(&controller_config);
}

void setup()
{
  setup_motors();
  setup_servos();
  setup_lights();
  setup_controller();
}

void loop()
{
}
