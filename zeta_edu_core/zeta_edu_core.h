#ifndef EDU_CORE_H_
#define EDU_CORE_H_

#include "src/configuration/pin_definition.h"

#include "src/include/imu/MPU9250.h"
#include "src/include/imu/MadgwickFilter.h"

#include <SoftwareSerial.h>

#define NUMBER_OF_TASK  2

#define IMU_SEND_FREQUENCY         100
#define COM_IND_TOGGLE_FREQUENCY   2
#define SONAR_MEASURE_FREQUENCY    10

#define SERIAL_SPEED     115200
#define SERIAL2_SPEED    115200
#define SERIAL3_SPEED    115200
#define RS485_SPEED      9600

#define TX_MAX_SIZE        64
#define POS_LENGTH         2
#define START_BYTE1        0xAA
#define START_BYTE2        0xBB
#define END_BYTE1          0xDD
#define END_BYTE2          0x55
#define IMU_DATA_LENGTH    41
#define SONAR_DATA_LENGTH  17

#define NUM_SONAR      4
#define MAX_DISTANCE   70.0f
#define SPEED_OF_SOUND 343.0f

union 
{
    float   num;
    uint8_t bytes[4];
}FloatToBytes; // little endian

enum
{
    task_num_send_imu = 0,
    task_num_sonar_measure,
    task_num_toggle_indicator,
};

enum class ParameterID : uint8_t
{
    pid_monitoring = 0,
    pid_set_velocity,
    pid_imu = 61,
    pid_sonar,
    pid_last,
};

volatile unsigned long time_sonar_travel[NUM_SONAR];  // Place to store traveltime of the pusle
volatile unsigned long time_sonar_start[NUM_SONAR];
float distance[NUM_SONAR];

#endif /* EDU_CORE_H_ */
