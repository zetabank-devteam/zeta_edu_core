#ifndef EDU_CORE_H_
#define EDU_CORE_H_
#define HW_VERSION "R0.1"
#define FW_VERSION "0.0.1"

#include "src/configuration/pin_definition.h"

#include "src/imu/MPU9250.h"
#include "src/imu/MadgwickFilter.h"
#include <ros.h>
#include <sensor_msgs/Imu.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/String.h>

#include <SoftwareSerial.h>

#define NUMBER_OF_TASK  4

#define IMU_SEND_FREQUENCY         100
#define COM_IND_TOGGLE_FREQUENCY   2
#define SONAR_MEASURE_FREQUENCY    10
#define PUB_VERSION_FREQUENCY      1

#define ROS_SERIAL_SPEED  115200
#define SERIAL_SPEED      115200
#define SERIAL2_SPEED     115200
#define SERIAL3_SPEED     115200
#define RS485_SPEED       9600

#define TX_MAX_SIZE        64
#define POS_LENGTH         2
#define START_BYTE1        0xAA
#define START_BYTE2        0xBB
#define END_BYTE1          0xDD
#define END_BYTE2          0x55
#define IMU_DATA_LENGTH    41
#define SONAR_DATA_LENGTH  17

#define NUM_SONAR       4
#define MAX_DISTANCE    70.0f
#define SPEED_OF_SOUND  343.0f

union 
{
    float   num;
    uint8_t bytes[4];
}FloatToBytes; // little endian

enum
{
    task_num_send_imu = 0,
    task_num_sonar_measure,
    task_num_pub_version,
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

SoftwareSerial RS485(USER_485_RX, USER_485_TX);
MPU9250 IMU(SPI, IMU_NCS);
Madgwick filter;

ros::NodeHandle nh;
sensor_msgs::Imu imu_msg;
ros::Publisher imu_publisher("imu", &imu_msg);
std_msgs::Float32MultiArray sonar_msg;
ros::Publisher sonar_publisher("sonar", &sonar_msg);
std_msgs::String hw_version_msg;
ros::Publisher hw_version_publisher("core_hw_version", &hw_version_msg);
std_msgs::String fw_version_msg;
ros::Publisher fw_version_publisher("core_fw_version", &fw_version_msg);
volatile unsigned long time_sonar_travel[NUM_SONAR];  // Place to store traveltime of the pusle
volatile unsigned long time_sonar_start[NUM_SONAR];
float distance[NUM_SONAR];

#endif /* EDU_CORE_H_ */
