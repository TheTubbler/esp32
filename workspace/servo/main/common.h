#ifndef MAIN_COMMON_H_
#define MAIN_COMMON_H_

#include <stdint.h>

/* Integer types */
typedef uint8_t u8;
typedef int8_t s8;
typedef uint16_t u16;
typedef int16_t s16;
typedef uint32_t u32;
typedef int32_t s32;
typedef uint64_t u64;
typedef int64_t s64;

/* Real types */
typedef float r32;
typedef double r32;

/* Miscellaneous types */
typedef char c8;
typedef bool b8;

/* Binary defines */
#define BIT0 (0b00000001)
#define BIT1 (0b00000010)
#define BIT2 (0b00000100)
#define BIT3 (0b00001000)
#define BIT4 (0b00010000)
#define BIT5 (0b00100000)
#define BIT6 (0b01000000)
#define BIT7 (0b10000000)

#endif /* MAIN_COMMON_H_ */
