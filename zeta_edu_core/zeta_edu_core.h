#ifndef ZETA_EDU_CORE_ZETA_EDU_CORE_H_
#define ZETA_EDU_CORE_ZETA_EDU_CORE_H_
#define HW_VERSION "R0.2" // RT_MOTOR_DRIVER_2ND
#define FW_VERSION "0.2.0"

#include "src/configuration/pin_definition.h"

#include "src/imu/ICM20689.h""
#include "src/imu/MadgwickFilter.h"
#include <ros.h>
#include <sensor_msgs/Imu.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/String.h>
#include <std_msgs/UInt8MultiArray.h>

#define NUMBER_OF_TASK  6

#define IMU_SEND_FREQUENCY            100
#define COM_IND_TOGGLE_FREQUENCY      2
#define SONAR_MEASURE_FREQUENCY       10
#define PUB_VERSION_FREQUENCY         1
#define PUB_LINE_DETECTION_FREQUENCY  20

#define ROS_SERIAL_SPEED  115200
#define SERIAL_SPEED      115200
#define SERIAL2_SPEED     115200
#define RS485_SPEED       9600

#define NUM_SONAR       4
#define MAX_DISTANCE    70.0f
#define SPEED_OF_SOUND  343.0f
#define NUM_LINE_DETECTOR  4
#define RS485              Serial3

enum
{
    task_num_send_imu = 0,
    task_num_sonar_measure,
    task_num_pub_version,
    task_num_toggle_indicator,
    task_num_pub_line_detection,
};

ICM20689 IMU(SPI, IMU_NCS);
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
std_msgs::UInt8MultiArray line_detector_msg;
ros::Publisher line_detector_publisher("line_detecting", &line_detector_msg);
volatile uint32_t time_sonar_travel[NUM_SONAR];  // Place to store traveltime of the pusle
volatile uint32_t time_sonar_start[NUM_SONAR];
float distance[NUM_SONAR];

#endif /* ZETA_EDU_CORE_ZETA_EDU_CORE_H_ */
