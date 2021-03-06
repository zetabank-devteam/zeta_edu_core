#include "zeta_edu_core.h"
// 20211118 Ahn, for increasing imu publishing hz, must expand tx buffer size of arduino serial driver
// C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino\HardwareSerial.h SERIAL_TX_BUFFER_SIZE
void setup()
{
    InitGPIO();
    InitIMU();
    InitSonar();
    InitSerial();
    InitROS();
}

////////////////////////////////
// Init functions
////////////////////////////////
void InitIMU()
{
    int status = IMU.begin();
    IMU.setDlpfBandwidth(ICM20689::DLPF_BANDWIDTH_21HZ);
    IMU.setSrd(19);    // hz = 1k / (1 + srd)
    IMU.enableDataReadyInterrupt();
    pinMode(IMU_INT, INPUT);
    attachInterrupt(digitalPinToInterrupt(IMU_INT), GetIMU, RISING);
    filter.begin(30);
}

void InitSonar()
{
    attachInterrupt(digitalPinToInterrupt(RS_ECHO1), ISR_SONAR1, CHANGE);
    attachInterrupt(digitalPinToInterrupt(RS_ECHO2), ISR_SONAR2, CHANGE);
    attachInterrupt(digitalPinToInterrupt(RS_ECHO3), ISR_SONAR3, CHANGE);
    attachInterrupt(digitalPinToInterrupt(RS_ECHO4), ISR_SONAR4, CHANGE);
    for(int i = 0; i < NUM_SONAR; i++)
    {
        time_sonar_travel[i] = 0;
        time_sonar_start[i]  = 0;
        distance[i]          = -1.0f;
    }
}

void InitGPIO()
{
    pinMode(USER_485_DIR, OUTPUT);
    pinMode(USER_LED2,    OUTPUT);
    pinMode(USER_LED1,    OUTPUT);
    pinMode(USER_DIP_SW2, INPUT);
    pinMode(USER_DIP_SW1, INPUT);
    pinMode(USER_BTN1,    INPUT);
    pinMode(TRIG,         OUTPUT);
    pinMode(RS_ECHO1,     INPUT);
    pinMode(RS_ECHO2,     INPUT);
    pinMode(RS_ECHO3,     INPUT);
    pinMode(RS_ECHO4,     INPUT);
    pinMode(COM_IND,      OUTPUT);
    pinMode(LINE_DETECT1, INPUT);
    pinMode(LINE_DETECT2, INPUT);
    pinMode(LINE_DETECT3, INPUT);
    pinMode(LINE_DETECT4, INPUT);
}

void InitROS()
{
    nh.getHardware()->setBaud(ROS_SERIAL_SPEED);
    nh.initNode();
    nh.advertise(imu_publisher);
    nh.advertise(sonar_publisher);
    nh.advertise(hw_version_publisher);
    nh.advertise(fw_version_publisher);
    nh.advertise(line_detector_publisher);
    imu_msg.header.frame_id = "imu_link";
    sonar_msg.data = (float*)malloc(sizeof(float) * NUM_SONAR);
    sonar_msg.data_length = NUM_SONAR;
    line_detector_msg.data = (uint8_t*)malloc(sizeof(uint8_t) * NUM_LINE_DETECTOR);
    line_detector_msg.data_length = NUM_LINE_DETECTOR;
    hw_version_msg.data = HW_VERSION;
    fw_version_msg.data = FW_VERSION;
}

void InitSerial()
{
#ifdef NO_ROS
    Serial.begin(SERIAL_SPEED);
#endif
    Serial2.begin(SERIAL2_SPEED);
    RS485.begin(RS485_SPEED);
}

////////////////////////////////
// ISR
////////////////////////////////
void GetIMU()
{ 
    // read the sensor
    IMU.readSensor();
    if(IMU.GetGyroCalibrated())
    {
        // filter.updateIMU(IMU.getGyroX_rads(), IMU.getGyroY_rads(), IMU.getGyroZ_rads(), 0.00001f, 0.00001f, -9.80665f);
        // 20211028 assume, no acceleration change in 2D planar motion
        filter.updateIMU(IMU.getGyroX_rads(), IMU.getGyroY_rads(), IMU.getGyroZ_rads(), 0.00001f, 0.00001f, -9.80665f);//, IMU.getMagX_uT(), IMU.getMagY_uT(), IMU.getMagZ_uT());
    }
}

void ISR_SONAR1()
{
    uint8_t pin_state = PINE >> 4 & 0b00000001; // arduino digitalRead() takes several uSeconds -> distance error!
    SonarHandler(pin_state, 0);
}

void ISR_SONAR2()
{
    uint8_t pin_state = PINE >> 5 & 0b00000001;
    SonarHandler(pin_state, 1);
}

void ISR_SONAR3()
{
    uint8_t pin_state = PIND >> 2 & 0b00000001;
    SonarHandler(pin_state, 2);
}

void ISR_SONAR4()
{
    uint8_t pin_state = PIND >> 0 & 0b00000001;
    SonarHandler(pin_state, 3);
}

inline __attribute__((always_inline)) void SonarHandler(bool pinState, int nIRQ)
{
    unsigned long time_cur = micros();  // Get current time (in ??s)
    if (pinState)
    {
        // If pin state has changed to HIGH -> remember start time (in ??s)
        time_sonar_start[nIRQ] = time_cur;
    }
    else
    {
        // If pin state has changed to LOW -> calculate time passed (in ??s)
        time_sonar_travel[nIRQ] = time_cur - time_sonar_start[nIRQ];
    }
}

////////////////////////////////
// Task functions
////////////////////////////////
void MeasureDistance()
{
    for (int i = 0; i < NUM_SONAR; i++)
    {
        distance[i] = time_sonar_travel[i] / 2.0 * (float)SPEED_OF_SOUND / 10000.0;
        if(distance[i] > MAX_DISTANCE)
        {
            distance[i] = MAX_DISTANCE;
        }
    }
    //noInterrupts();
    digitalWrite(TRIG, 1);
    delayMicroseconds(10);
    digitalWrite(TRIG, 0);
    //interrupts();
}

void SendSonar()
{
    for(int i = 0; i < NUM_SONAR; i++)
    {
        sonar_msg.data[i] = distance[i]; 
    }
    sonar_publisher.publish(&sonar_msg);
}

void SendImu()
{
    imu_msg.header.stamp = nh.now();
    imu_msg.orientation.w = filter.q0;
    imu_msg.orientation.x = filter.q1;
    imu_msg.orientation.y = filter.q2;
    imu_msg.orientation.z = filter.q3;
            
    imu_msg.angular_velocity.x = IMU.getGyroX_rads();
    imu_msg.angular_velocity.y = IMU.getGyroY_rads();
    imu_msg.angular_velocity.z = IMU.getGyroZ_rads();
    imu_msg.linear_acceleration.x = 0.0f;
    imu_msg.linear_acceleration.y = 0.0f;
    imu_msg.linear_acceleration.z = 9.80665f;
    imu_publisher.publish(&imu_msg);
}

void PublishVersionInfo()
{
    hw_version_publisher.publish(&hw_version_msg);
    fw_version_publisher.publish(&fw_version_msg);
}

void PublishLineDetection()
{
    line_detector_publisher.publish(&line_detector_msg);
}

void DetectLine()
{
    digitalRead(LINE_DETECT1)? line_detector_msg.data[0] = 1 : line_detector_msg.data[0] = 0;
    digitalRead(LINE_DETECT2)? line_detector_msg.data[1] = 1 : line_detector_msg.data[1] = 0;
    digitalRead(LINE_DETECT3)? line_detector_msg.data[2] = 1 : line_detector_msg.data[2] = 0;
    digitalRead(LINE_DETECT4)? line_detector_msg.data[3] = 1 : line_detector_msg.data[3] = 0;
}

void BlinkLed1()
{
    digitalWrite(USER_LED1, !digitalRead(USER_LED1));
}

void BlinkLed2()
{
    digitalWrite(USER_LED2, !digitalRead(USER_LED2));
}

void PrintSwitchState()
{
//    Serial.print("Switch: ");Serial.print(digitalRead(USER_DIP_SW1), DEC);Serial.print(" ");Serial.println(digitalRead(USER_DIP_SW2), DEC);
}

void PrintBtnState()
{
//    Serial.print("Button: ");Serial.println(digitalRead(USER_BTN1), DEC);
}

void ToggleComIndicator()
{
   digitalWrite(COM_IND, !digitalRead(COM_IND));
}

////////////////////////////////
// loop
////////////////////////////////
void loop() {
    static uint32_t time_pre[NUMBER_OF_TASK];
    uint32_t time_cur = millis();
    if(time_cur - time_pre[task_num_send_imu] >= (1000 / IMU_SEND_FREQUENCY))
    {
        SendImu();
        time_pre[task_num_send_imu] = time_cur;
    }
    time_cur = millis();
    if(time_cur - time_pre[task_num_sonar_measure] >= (1000 / SONAR_MEASURE_FREQUENCY))
    {
        MeasureDistance();
        SendSonar();
        time_pre[task_num_sonar_measure] = time_cur;
    }
    time_cur = millis();
    if(time_cur - time_pre[task_num_pub_line_detection] >= (1000 / PUB_LINE_DETECTION_FREQUENCY))
    {
        DetectLine();
        PublishLineDetection();
        time_pre[task_num_pub_line_detection] = time_cur;
    }
    time_cur = millis();
    if(time_cur - time_pre[task_num_toggle_indicator] >= (1000 / COM_IND_TOGGLE_FREQUENCY))
    {
        ToggleComIndicator();
        time_pre[task_num_toggle_indicator] = time_cur;
    }
    time_cur = millis();
    if(time_cur - time_pre[task_num_pub_version] >= (1000 / PUB_VERSION_FREQUENCY))
    {
        PublishVersionInfo();
        time_pre[task_num_pub_version] = time_cur;
    }
#ifndef NO_ROS
    nh.spinOnce();
#endif
}

/* zeta_edu_core.ino */
