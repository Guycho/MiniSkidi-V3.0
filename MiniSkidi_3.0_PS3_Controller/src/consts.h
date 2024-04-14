#include <Arduino.h>
namespace Consts{
    const uint8_t RIGHT_MOTOR_PWM_PIN_1 = 25;
    const uint8_t RIGHT_MOTOR_PWM_PIN_2 = 26;
    const double RIGHT_MOTOR_MAX_PERCENTAGE_DC = 100;
    const double RIGHT_MOTOR_MIN_SPEED = 0;
    const double RIGHT_MOTOR_DEAD_BAND = 20;
    const bool RIGHT_MOTOR_REVERSE = false;

    const uint8_t LEFT_MOTOR_PWM_PIN_1 = 33;
    const uint8_t LEFT_MOTOR_PWM_PIN_2 = 32;
    const double LEFT_MOTOR_MAX_PERCENTAGE_DC = 100;
    const double LEFT_MOTOR_MIN_SPEED = 0;
    const double LEFT_MOTOR_DEAD_BAND = 20;
    const bool LEFT_MOTOR_REVERSE = false;

    const uint8_t ARM_MOTOR_PWM_PIN_1 = 21;
    const uint8_t ARM_MOTOR_PWM_PIN_2 = 19;
    const double ARM_MOTOR_MAX_PERCENTAGE_DC = 100;
    const double ARM_MOTOR_MIN_SPEED = 0;
    const double ARM_MOTOR_DEAD_BAND = 20;
    const bool ARM_MOTOR_REVERSE = false;

    const uint8_t BUCKET_SERVO_PPM_PIN = 23;
    const uint8_t BUCKET_SERVO_INIT_POS = 140;
    const uint8_t BUCKET_SERVO_MIN_POS = 0;
    const uint8_t BUCKET_SERVO_MAX_POS = 180;
    const bool BUCKET_SERVO_REVERSE = false;

    const uint8_t CLAW_SERVO_PPM_PIN = 22;
    const uint8_t CLAW_SERVO_INIT_POS = 150;
    const uint8_t CLAW_SERVO_MIN_POS = 0;
    const uint8_t CLAW_SERVO_MAX_POS = 180;
    const bool CLAW_SERVO_REVERSE = false;

    const uint8_t AUX_LIGHTS_POSITIVE_PIN = 18;
    const uint8_t AUX_LIGHTS_NEGATIVE_PIN = 5;
    const bool AUX_LIGHT_INIT_STATE = false;

    const double BUCKET_LOGIC_DEGREES_PER_SECOND = 45;

    const double CLAW_LOGIC_DEGREES_PER_SECOND = 45;

    const String PS3_CONTROLLER_CONNECTION_STRING = "a0:5a:5a:a0:0f:98";

    const double FALLBACK_DEGREES_PER_SECOND_LOGIC = 45;
}