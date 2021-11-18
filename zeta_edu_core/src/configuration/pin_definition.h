#ifndef ZETA_EDU_CORE_PIN_DEFINITION_H_
#define ZETA_EDU_CORE_PIN_DEFINITION_H_
#include "pins_arduino_mega.h"
//////////////////////////////////////////////////////////
// Pin definition
//////////////////////////////////////////////////////////
#define COM_IND       PIN_PB7
#define USER_LED2     PIN_PL5
#define USER_LED1     PIN_PL4

#define USER_DIP_SW2  PIN_PL3
#define USER_DIP_SW1  PIN_PL2
#define USER_BTN1     PIN_PL1

#define TRIG          PIN_PL0
#define RS_ECHO1      PIN_PE4
#define RS_ECHO2      PIN_PE5
#define RS_ECHO3      PIN_PD2
#define RS_ECHO4      PIN_PD0

#define USER_485_TX   PIN_PK1
#define USER_485_RX   PIN_PK0
#define USER_485_DIR  PIN_PL6

#define IMU_NCS       PIN_PB0
#define IMU_INT       PIN_PD3

#define EXT_GPIO1     PIN_PG5
#define EXT_GPIO2     PIN_PE3
#define EXT_GPIO3     PIN_PH3
#define EXT_GPIO4     PIN_PH4
#define EXT_GPIO5     PIN_PH5
#define EXT_GPIO6     PIN_PH6
#define EXT_GPIO7     PIN_PB4
#define EXT_GPIO8     PIN_PB6
#define EXT_GPIO9     PIN_PA0
#define EXT_GPIO10    PIN_PA1
#define EXT_GPIO11    PIN_PA2
#define EXT_GPIO12    PIN_PA3
#define EXT_GPIO13    PIN_PA4
#define EXT_GPIO14    PIN_PA5
#define EXT_GPIO15    PIN_PA6
#define EXT_GPIO16    PIN_PA7
#define EXT_ADC1      PIN_PF0
#define EXT_ADC2      PIN_PF1
#define EXT_ADC3      PIN_PF2
#define EXT_ADC4      PIN_PF3
#define EXT_PWM1      PIN_PF4
#define EXT_PWM2      PIN_PF5
#define EXT_PWM3      PIN_PF6
#define EXT_PWM4      PIN_PF7

#define LINE_DETECT1  EXT_GPIO1
#define LINE_DETECT2  EXT_GPIO2
#define LINE_DETECT3  EXT_GPIO3
#define LINE_DETECT4  EXT_GPIO4
#endif /* ZETA_EDU_CORE_PIN_DEFINITION_H_ */