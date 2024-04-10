#include <Arduino.h>
namespace Consts{
    uint8_t RIGHT_MOTOR_PWM_PIN_1 = 25;
    uint8_t RIGHT_MOTOR_PWM_PIN_2 = 26;
    double RIGHT_MOTOR_MAX_PERCENTAGE_DC = 100;
    double RIGHT_MOTOR_MIN_SPEED = 0;
    double RIGHT_MOTOR_DEAD_BAND = 20;
    bool RIGHT_MOTOR_REVERSE = false;

    uint8_t LEFT_MOTOR_PWM_PIN_1 = 33;
    uint8_t LEFT_MOTOR_PWM_PIN_2 = 32;
    double LEFT_MOTOR_MAX_PERCENTAGE_DC = 100;
    double LEFT_MOTOR_MIN_SPEED = 0;
    double LEFT_MOTOR_DEAD_BAND = 20;
    bool LEFT_MOTOR_REVERSE = false;

    uint8_t ARM_MOTOR_PWM_PIN_1 = 21;
    uint8_t ARM_MOTOR_PWM_PIN_2 = 19;
    double ARM_MOTOR_MAX_PERCENTAGE_DC = 100;
    double ARM_MOTOR_MIN_SPEED = 0;
    double ARM_MOTOR_DEAD_BAND = 20;
    bool ARM_MOTOR_REVERSE = false;

    uint8_t BUCKET_SERVO_PIN = 23;
    uint8_t CLAW_SERVO_PIN = 22;

    uint8_t AUX_LIGHTS_POSITIVE_PIN = 18;
    uint8_t AUX_LIGHTS_NEGATIVE_PIN = 5;
    bool AUX_LIGHT_INIT_STATE = false;
}