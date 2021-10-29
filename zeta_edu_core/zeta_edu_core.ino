#include "zeta_edu_core.h"

SoftwareSerial RS485(USER_485_RX, USER_485_TX);
MPU9250 IMU(SPI,IMU_NCS);
Madgwick filter;
// 485 class
// Dip switch
// exteral gpio definition
// battery?
// sonar trigger & measure
// sonar publish
// user led class
// user switch class

void setup()
{
    InitGPIO();
    InitIMU();
    InitSonar();
    InitSerial();
}

////////////////////////////////
// Init functions
////////////////////////////////
void InitIMU()
{
    int status = IMU.begin();
    IMU.setDlpfBandwidth(MPU9250::DLPF_BANDWIDTH_41HZ);
    IMU.setSrd(9);    // hz = 1k / (1 + srd)
    IMU.enableDataReadyInterrupt();
    pinMode(IMU_INT, INPUT);
    attachInterrupt(digitalPinToInterrupt(IMU_INT), GetIMU, RISING);
    IMU.calibrateGyro(); // 캘리브레이션 시간동안 구동 & 이동 금지
    filter.begin(100);
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
        time_sonar_start[i] = 0;
        distance[i] = 0.0f;
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
}

void InitSerial()
{
    Serial.begin(SERIAL_SPEED);
    Serial2.begin(SERIAL2_SPEED);
    Serial3.begin(SERIAL3_SPEED);
    RS485.begin(RS485_SPEED);
    while(!Serial) // wait before connect
    {
        ToggleComIndicator();
        delay(1000);
    }
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
        filter.updateIMU(IMU.getGyroX_rads(), IMU.getGyroY_rads(), IMU.getGyroZ_rads(), 0.00001f, 0.00001f, -9.80665f);
        // 20211028 assume, no acceleration change in 2D planar motion
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

inline void SonarHandler(bool pinState, int nIRQ)
{
    unsigned long time_cur = micros();  // Get current time (in µs)
    if (pinState)
    {
        // If pin state has changed to HIGH -> remember start time (in µs)
        time_sonar_start[nIRQ] = time_cur;
    }
    else
    {
        // If pin state has changed to LOW -> calculate time passed (in µs)
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
    uint8_t tx_data[TX_MAX_SIZE] = {0,};
    int tx_index = 0;
    int i = 0;
    tx_data[tx_index++] = START_BYTE1;
    tx_data[tx_index++] = START_BYTE2;
    tx_data[tx_index++] = SONAR_DATA_LENGTH;
    tx_data[tx_index++] = static_cast<uint8_t>(ParameterID::pid_sonar);
    noInterrupts();
    for(int j = 0; j < NUM_SONAR; j++)
    {
        FloatToBytes.num = distance[j];
        for(i = 0; i < 4; i++)
        {
            tx_data[tx_index++] = FloatToBytes.bytes[i];
        }
    }
    interrupts();
    tx_data[tx_index] = Checksum(tx_data, tx_index);
    tx_index++;
    tx_data[tx_index++] = END_BYTE1;
    tx_data[tx_index++] = END_BYTE2;
    Serial.write(tx_data, tx_index);
}

void SendImu()
{
    uint8_t tx_data[TX_MAX_SIZE] = {0,};
    int tx_index = 0;
    int i = 0;
    tx_data[tx_index++] = START_BYTE1;
    tx_data[tx_index++] = START_BYTE2;
    tx_data[tx_index++] = IMU_DATA_LENGTH;
    tx_data[tx_index++] = static_cast<uint8_t>(ParameterID::pid_imu);
    noInterrupts();
    FloatToBytes.num = IMU.getAccelX_mss();
    for(i = 0; i < 4; i++)
    {
        tx_data[tx_index++] = FloatToBytes.bytes[i];
    }
    FloatToBytes.num = IMU.getAccelY_mss();
    for(i = 0; i < 4; i++)
    {
        tx_data[tx_index++] = FloatToBytes.bytes[i];
    }
    FloatToBytes.num = IMU.getAccelZ_mss();
    for(i = 0; i < 4; i++)
    {
        tx_data[tx_index++] = FloatToBytes.bytes[i];
    }
    FloatToBytes.num = IMU.getGyroX_rads();
    for(i = 0; i < 4; i++)
    {
        tx_data[tx_index++] = FloatToBytes.bytes[i];
    }
    FloatToBytes.num = IMU.getGyroY_rads();
    for(i = 0; i < 4; i++)
    {
        tx_data[tx_index++] = FloatToBytes.bytes[i];
    }
    FloatToBytes.num = IMU.getGyroZ_rads();
    for(i = 0; i < 4; i++)
    {
        tx_data[tx_index++] = FloatToBytes.bytes[i];
    }
    FloatToBytes.num = filter.q0;
    for(i = 0; i < 4; i++)
    {
        tx_data[tx_index++] = FloatToBytes.bytes[i];
    }
    FloatToBytes.num = filter.q1;
    for(i = 0; i < 4; i++)
    {
        tx_data[tx_index++] = FloatToBytes.bytes[i];
    }
    FloatToBytes.num = filter.q2;
    for(i = 0; i < 4; i++)
    {
        tx_data[tx_index++] = FloatToBytes.bytes[i];
    }
    FloatToBytes.num = filter.q3;
    for(i = 0; i < 4; i++)
    {
        tx_data[tx_index++] = FloatToBytes.bytes[i];
    }
    interrupts();
    tx_data[tx_index] = Checksum(tx_data, tx_index);
    tx_index++;
    tx_data[tx_index++] = END_BYTE1;
    tx_data[tx_index++] = END_BYTE2;
    Serial.write(tx_data, tx_index);
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
//    digitalWrite(COM_IND, !digitalRead(COM_IND));
}

////////////////////////////////
// other functions
////////////////////////////////
uint8_t Checksum(uint8_t data[], int length)
{
    uint16_t sum = 0;
    for(int i = POS_LENGTH; i < length; i++)
    {
        sum += data[i];
    }
    return sum & 0xFF;
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
    if(time_cur - time_pre[task_num_sonar_measure] >= (1000 / SONAR_MEASURE_FREQUENCY))
    {
        MeasureDistance();
        SendSonar();
        time_pre[task_num_sonar_measure] = time_cur;
    }
    if(time_cur - time_pre[task_num_toggle_indicator] >= (1000 / COM_IND_TOGGLE_FREQUENCY))
    {
        ToggleComIndicator();
        time_pre[task_num_toggle_indicator] = time_cur;
    }
}

/* zeta_edu_core.ino */
