#ifndef MAIN_APP_COMMON_H_
#define MAIN_APP_COMMON_H_

#include "common.h"
#include "PCA9685.h"

#define PRE_SCALE_VALUE 0x79 // This is the prescale value to get 50Hz update frequency
// 0x79 = 121 = round(25MHz / 4096 / 50Hz) - 1, where
// 25MHz is IC internal clock frequency,
// 4096 = 2^12 is the tick resolution (12 bit), and
// 50Hz is the desired PWM frequency

#define SERVO_ADDRESS PCA9685_BASE_ADDRESS

#endif /* MAIN_APP_COMMON_H_ */
