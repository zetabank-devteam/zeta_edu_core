#ifndef _ROS_zetabot_main_BatteryInformationMsgs_h
#define _ROS_zetabot_main_BatteryInformationMsgs_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace zetabot_main
{

  class BatteryInformationMsgs : public ros::Msg
  {
    public:
      typedef int16_t _id_type;
      _id_type id;
      typedef float _voltage_type;
      _voltage_type voltage;
      typedef float _current_type;
      _current_type current;
      typedef uint16_t _status_type;
      _status_type status;
      typedef uint16_t _time_to_full_type;
      _time_to_full_type time_to_full;
      typedef uint16_t _time_to_empty_type;
      _time_to_empty_type time_to_empty;
      typedef uint8_t _SOC_type;
      _SOC_type SOC;
      typedef uint8_t _SOH_type;
      _SOH_type SOH;
      typedef float _remaining_capacity_type;
      _remaining_capacity_type remaining_capacity;
      typedef float _available_energy_type;
      _available_energy_type available_energy;
      typedef float _temperature_type;
      _temperature_type temperature;

    BatteryInformationMsgs():
      id(0),
      voltage(0),
      current(0),
      status(0),
      time_to_full(0),
      time_to_empty(0),
      SOC(0),
      SOH(0),
      remaining_capacity(0),
      available_energy(0),
      temperature(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->id);
      union {
        float real;
        uint32_t base;
      } u_voltage;
      u_voltage.real = this->voltage;
      *(outbuffer + offset + 0) = (u_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voltage);
      union {
        float real;
        uint32_t base;
      } u_current;
      u_current.real = this->current;
      *(outbuffer + offset + 0) = (u_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current);
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->status >> (8 * 1)) & 0xFF;
      offset += sizeof(this->status);
      *(outbuffer + offset + 0) = (this->time_to_full >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_to_full >> (8 * 1)) & 0xFF;
      offset += sizeof(this->time_to_full);
      *(outbuffer + offset + 0) = (this->time_to_empty >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_to_empty >> (8 * 1)) & 0xFF;
      offset += sizeof(this->time_to_empty);
      *(outbuffer + offset + 0) = (this->SOC >> (8 * 0)) & 0xFF;
      offset += sizeof(this->SOC);
      *(outbuffer + offset + 0) = (this->SOH >> (8 * 0)) & 0xFF;
      offset += sizeof(this->SOH);
      union {
        float real;
        uint32_t base;
      } u_remaining_capacity;
      u_remaining_capacity.real = this->remaining_capacity;
      *(outbuffer + offset + 0) = (u_remaining_capacity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_remaining_capacity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_remaining_capacity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_remaining_capacity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->remaining_capacity);
      union {
        float real;
        uint32_t base;
      } u_available_energy;
      u_available_energy.real = this->available_energy;
      *(outbuffer + offset + 0) = (u_available_energy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_available_energy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_available_energy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_available_energy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->available_energy);
      union {
        float real;
        uint32_t base;
      } u_temperature;
      u_temperature.real = this->temperature;
      *(outbuffer + offset + 0) = (u_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temperature);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id = u_id.real;
      offset += sizeof(this->id);
      union {
        float real;
        uint32_t base;
      } u_voltage;
      u_voltage.base = 0;
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->voltage = u_voltage.real;
      offset += sizeof(this->voltage);
      union {
        float real;
        uint32_t base;
      } u_current;
      u_current.base = 0;
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current = u_current.real;
      offset += sizeof(this->current);
      this->status =  ((uint16_t) (*(inbuffer + offset)));
      this->status |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->status);
      this->time_to_full =  ((uint16_t) (*(inbuffer + offset)));
      this->time_to_full |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->time_to_full);
      this->time_to_empty =  ((uint16_t) (*(inbuffer + offset)));
      this->time_to_empty |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->time_to_empty);
      this->SOC =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->SOC);
      this->SOH =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->SOH);
      union {
        float real;
        uint32_t base;
      } u_remaining_capacity;
      u_remaining_capacity.base = 0;
      u_remaining_capacity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_remaining_capacity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_remaining_capacity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_remaining_capacity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->remaining_capacity = u_remaining_capacity.real;
      offset += sizeof(this->remaining_capacity);
      union {
        float real;
        uint32_t base;
      } u_available_energy;
      u_available_energy.base = 0;
      u_available_energy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_available_energy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_available_energy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_available_energy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->available_energy = u_available_energy.real;
      offset += sizeof(this->available_energy);
      union {
        float real;
        uint32_t base;
      } u_temperature;
      u_temperature.base = 0;
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temperature = u_temperature.real;
      offset += sizeof(this->temperature);
     return offset;
    }

    const char * getType(){ return "zetabot_main/BatteryInformationMsgs"; };
    const char * getMD5(){ return "1c5efe232c76a25ed0b936990e171934"; };

  };

}
#endif