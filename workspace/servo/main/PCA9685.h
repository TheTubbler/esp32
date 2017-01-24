#ifndef MAIN_PCA9685_H_
#define MAIN_PCA9685_H_

#include "common.h"

#define PCA9685_BASE_ADDRESS    BIT7 // the servo base address
#define PCA9685_A0_ADDRESS      BIT1
#define PCA9685_A1_ADDRESS      BIT2
#define PCA9685_A2_ADDRESS      BIT3
#define PCA9685_A3_ADDRESS      BIT4
#define PCA9685_A4_ADDRESS      BIT5
#define PCA9685_A5_ADDRESS      BIT6

#define PCA9685_MODE1           (0x00)
#define PCA9685_MODE2           (0x01)
#define PCA9685_SUBADR1         (0x02)
#define PCA9685_SUBADR2         (0x03)
#define PCA9685_SUBADR3         (0x04)
#define PCA9685_ALLCALLADR      (0x05)
#define PCA9685_LED0_ON_L       (0x06)
#define PCA9685_LED0_ON_H       (0x07)
#define PCA9685_LED0_OFF_L      (0x08)
#define PCA9685_LED0_OFF_H      (0x09)
#define PCA9685_LED1_ON_L       (0x0A)
#define PCA9685_LED1_ON_H       (0x0B)
#define PCA9685_LED1_OFF_L      (0x0C)
#define PCA9685_LED1_OFF_H      (0x0D)
#define PCA9685_LED2_ON_L       (0x0E)
#define PCA9685_LED2_ON_H       (0x0F)
#define PCA9685_LED2_OFF_L      (0x10)
#define PCA9685_LED2_OFF_H      (0x11)
#define PCA9685_LED3_ON_L       (0x12)
#define PCA9685_LED3_ON_H       (0x13)
#define PCA9685_LED3_OFF_L      (0x14)
#define PCA9685_LED3_OFF_H      (0x15)
#define PCA9685_LED4_ON_L       (0x16)
#define PCA9685_LED4_ON_H       (0x17)
#define PCA9685_LED4_OFF_L      (0x18)
#define PCA9685_LED4_OFF_H      (0x19)
#define PCA9685_LED5_ON_L       (0x1A)
#define PCA9685_LED5_ON_H       (0x1B)
#define PCA9685_LED5_OFF_L      (0x1C)
#define PCA9685_LED5_OFF_H      (0x1D)
#define PCA9685_LED6_ON_L       (0x1E)
#define PCA9685_LED6_ON_H       (0x1F)
#define PCA9685_LED6_OFF_L      (0x20)
#define PCA9685_LED6_OFF_H      (0x21)
#define PCA9685_LED7_ON_L       (0x22)
#define PCA9685_LED7_ON_H       (0x23)
#define PCA9685_LED7_OFF_L      (0x24)
#define PCA9685_LED7_OFF_H      (0x25)
#define PCA9685_LED8_ON_L       (0x26)
#define PCA9685_LED8_ON_H       (0x27)
#define PCA9685_LED8_OFF_L      (0x28)
#define PCA9685_LED8_OFF_H      (0x29)
#define PCA9685_LED9_ON_L       (0x2A)
#define PCA9685_LED9_ON_H       (0x2B)
#define PCA9685_LED9_OFF_L      (0x2C)
#define PCA9685_LED9_OFF_H      (0x2D)
#define PCA9685_LED10_ON_L      (0x2E)
#define PCA9685_LED10_ON_H      (0x2F)
#define PCA9685_LED10_OFF_L     (0x30)
#define PCA9685_LED10_OFF_H     (0x31)
#define PCA9685_LED11_ON_L      (0x32)
#define PCA9685_LED11_ON_H      (0x33)
#define PCA9685_LED11_OFF_L     (0x34)
#define PCA9685_LED11_OFF_H     (0x35)
#define PCA9685_LED12_ON_L      (0x36)
#define PCA9685_LED12_ON_H      (0x37)
#define PCA9685_LED12_OFF_L     (0x38)
#define PCA9685_LED12_OFF_H     (0x39)
#define PCA9685_LED13_ON_L      (0x3A)
#define PCA9685_LED13_ON_H      (0x3B)
#define PCA9685_LED13_OFF_L     (0x3C)
#define PCA9685_LED13_OFF_H     (0x3D)
#define PCA9685_LED14_ON_L      (0x3E)
#define PCA9685_LED14_ON_H      (0x3F)
#define PCA9685_LED14_OFF_L     (0x40)
#define PCA9685_LED14_OFF_H     (0x41)
#define PCA9685_LED15_ON_L      (0x42)
#define PCA9685_LED15_ON_H      (0x43)
#define PCA9685_LED15_OFF_L     (0x44)
#define PCA9685_LED15_OFF_H     (0x45)
                              /* .... Addresses reserved for future use */
#define PCA9685_ALL_LED_ON_L    (0xFA)
#define PCA9685_ALL_LED_ON_H    (0xFB)
#define PCA9685_ALL_LED_OFF_L   (0xFC)
#define PCA9685_ALL_LED_OFF_H   (0xFD)
#define PCA9685_PRE_SCALE       (0xFE)
#define PCA9685_TESTMODE        (0xFF)

#define PCA9685_MODE1_RESTART   BIT7 // R/W, def=0
#define PCA9685_MODE1_EXTCLK    BIT6 // R/W, def=0
#define PCA9685_MODE1_AI        BIT5 // R/W, def=0
#define PCA9685_MODE1_SLEEP     BIT4 // R/W, def=1
#define PCA9685_MODE1_SUB1      BIT3 // R/W, def=0
#define PCA9685_MODE1_SUB2      BIT2 // R/W, def=0
#define PCA9685_MODE1_SUB3      BIT1 // R/W, def=0
#define PCA9685_MODE1_ALLCALL   BIT0 // R/W, def=1

#define PCA9685_MODE2_INVRT     BIT4 // R/W, def=1
#define PCA9685_MODE2_OCH       BIT3 // R/W, def=0
#define PCA9685_MODE2_OUTDRV    BIT2 // R/W, def=1
#define PCA9685_MODE2_OUTNE1    BIT1 // R/W, def=0
#define PCA9685_MODE2_OUTNE0    BIT0 // R/W, def=0

#define PCA9685_SUBADR1_7       BIT7 // R/W, def=1
#define PCA9685_SUBADR1_6       BIT6 // R/W, def=1
#define PCA9685_SUBADR1_5       BIT5 // R/W, def=1
#define PCA9685_SUBADR1_4       BIT4 // R/W, def=0
#define PCA9685_SUBADR1_3       BIT3 // R/W, def=0
#define PCA9685_SUBADR1_2       BIT2 // R/W, def=0
#define PCA9685_SUBADR1_1       BIT1 // R/W, def=1

#define PCA9685_SUBADR2_7       BIT7 // R/W, def=1
#define PCA9685_SUBADR2_6       BIT6 // R/W, def=1
#define PCA9685_SUBADR2_5       BIT5 // R/W, def=1
#define PCA9685_SUBADR2_4       BIT4 // R/W, def=0
#define PCA9685_SUBADR2_3       BIT3 // R/W, def=0
#define PCA9685_SUBADR2_2       BIT2 // R/W, def=1
#define PCA9685_SUBADR2_1       BIT1 // R/W, def=0

#define PCA9685_SUBADR3_7       BIT7 // R/W, def=1
#define PCA9685_SUBADR3_6       BIT6 // R/W, def=1
#define PCA9685_SUBADR3_5       BIT5 // R/W, def=1
#define PCA9685_SUBADR3_4       BIT4 // R/W, def=0
#define PCA9685_SUBADR3_3       BIT3 // R/W, def=1
#define PCA9685_SUBADR3_2       BIT2 // R/W, def=0
#define PCA9685_SUBADR3_1       BIT1 // R/W, def=0

#define PCA9685_ALLCALLADR_7    BIT7 // R/W, def=1
#define PCA9685_ALLCALLADR_6    BIT6 // R/W, def=1
#define PCA9685_ALLCALLADR_5    BIT5 // R/W, def=1
#define PCA9685_ALLCALLADR_4    BIT4 // R/W, def=0
#define PCA9685_ALLCALLADR_3    BIT3 // R/W, def=0
#define PCA9685_ALLCALLADR_2    BIT2 // R/W, def=0
#define PCA9685_ALLCALLADR_1    BIT1 // R/W, def=0

#define PCA9685_FULL_LED_ON_H   BIT4 // R/W, def=0
#define PCA9685_FULL_LED_OFF_H  BIT4 // R/W, def=0

/* This function simply masks the input value so it is a valid led value */
void
PCA9685GetMaskedLedValues(u8 * highOut, u8 * lowOut, u16 valueIn);


#endif /* MAIN_PCA9685_H_ */
