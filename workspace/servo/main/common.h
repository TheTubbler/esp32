/*
 * common.h
 *
 *  Created on: 21 jan. 2017
 *      Author: jae91
 */

#ifndef MAIN_COMMON_H_
#define MAIN_COMMON_H_

#define PRE_SCALE_ADDRESS 0xFE // This is the prescale address
#define PRE_SCALE_VALUE 0x79 // This is the prescale value to get 50Hz update frequency
// 0x79 = 121 = round(25MHz / 4096 / 50Hz) - 1, where
// 25MHz is ic clock frequency,
// 4096 is the tick resolution, and
// 50Hz is the desired PWM frequency

#define SERVO_ADDRESS 0x80 // = 0b1000 0000, the

#endif /* MAIN_COMMON_H_ */
