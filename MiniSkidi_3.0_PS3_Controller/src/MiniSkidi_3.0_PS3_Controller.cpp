#include <Ps3Controller.h>
#include "motor/DRV8833-motor.h"
#include "lights/dual-gpio-lights.h"
#include "consts.h"

/*
motion LX + LY
arm RY
aux lights R3
bucket up r2 down l2
claw up r1 down l1
*/

DRV8833Motor right_motor;
DRV8833Motor left_motor;
DRV8833Motor arm_motor;

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

void setup_lights()
{
  DualGpioLightsConfig aux_lights_config;
  aux_lights_config.positive_pin = Consts::AUX_LIGHTS_POSITIVE_PIN;
  aux_lights_config.negative_pin = Consts::AUX_LIGHTS_NEGATIVE_PIN;
  aux_lights_config.init_state = Consts::AUX_LIGHT_INIT_STATE;
  aux_lights.init(&aux_lights_config);
}

void run()
{
  return;
}

Servo bucketServo;
Servo clawServo;

int bucketServoValue = 140;
int clawServoValue = 150;
int servoDelay = 0;

bool moveClawServoUp = false;
bool moveClawServoDown = false;
bool moveBucketServoUp = false;
bool moveBucketServoDown = false;

void onConnect()
{
  Serial.println("Connected.");
}

void setup()
{

  Serial.begin(115200);

  Ps3.attach(run);
  Ps3.attachOnConnect(onConnect);
  Ps3.begin("a0:5a:5a:a0:0f:98");

  Serial.println("Ready.");

  bucketServo.attach(bucketServoPin);
  clawServo.attach(clawServoPin);

  bucketServo.write(bucketServoValue);
  clawServo.write(clawServoValue);
}

void loop()
{
  if (!Ps3.isConnected())
    return;
  delay(500);
}
