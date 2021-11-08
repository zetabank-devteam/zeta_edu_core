#ifndef _ROS_zetabot_main_EnvironmentMsgs_h
#define _ROS_zetabot_main_EnvironmentMsgs_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace zetabot_main
{

  class EnvironmentMsgs : public ros::Msg
  {
    public:
      typedef float _Dust_PM2_5_ugm3_type;
      _Dust_PM2_5_ugm3_type Dust_PM2_5_ugm3;
      typedef float _Dust_PM10_ugm3_type;
      _Dust_PM10_ugm3_type Dust_PM10_ugm3;
      typedef float _CO2_ppm_type;
      _CO2_ppm_type CO2_ppm;
      typedef float _Ozone_ppm_type;
      _Ozone_ppm_type Ozone_ppm;
      typedef float _HCHO_ugm3_type;
      _HCHO_ugm3_type HCHO_ugm3;
      typedef float _CO_ppm_type;
      _CO_ppm_type CO_ppm;
      typedef float _NO2_ppm_type;
      _NO2_ppm_type NO2_ppm;
      typedef float _Rn_Bqm3_type;
      _Rn_Bqm3_type Rn_Bqm3;
      typedef float _TVOCs_ugm3_type;
      _TVOCs_ugm3_type TVOCs_ugm3;
      typedef float _temp_celcius_type;
      _temp_celcius_type temp_celcius;
      typedef float _hum_RHp_type;
      _hum_RHp_type hum_RHp;

    EnvironmentMsgs():
      Dust_PM2_5_ugm3(0),
      Dust_PM10_ugm3(0),
      CO2_ppm(0),
      Ozone_ppm(0),
      HCHO_ugm3(0),
      CO_ppm(0),
      NO2_ppm(0),
      Rn_Bqm3(0),
      TVOCs_ugm3(0),
      temp_celcius(0),
      hum_RHp(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_Dust_PM2_5_ugm3;
      u_Dust_PM2_5_ugm3.real = this->Dust_PM2_5_ugm3;
      *(outbuffer + offset + 0) = (u_Dust_PM2_5_ugm3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Dust_PM2_5_ugm3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Dust_PM2_5_ugm3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Dust_PM2_5_ugm3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Dust_PM2_5_ugm3);
      union {
        float real;
        uint32_t base;
      } u_Dust_PM10_ugm3;
      u_Dust_PM10_ugm3.real = this->Dust_PM10_ugm3;
      *(outbuffer + offset + 0) = (u_Dust_PM10_ugm3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Dust_PM10_ugm3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Dust_PM10_ugm3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Dust_PM10_ugm3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Dust_PM10_ugm3);
      union {
        float real;
        uint32_t base;
      } u_CO2_ppm;
      u_CO2_ppm.real = this->CO2_ppm;
      *(outbuffer + offset + 0) = (u_CO2_ppm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_CO2_ppm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_CO2_ppm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_CO2_ppm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->CO2_ppm);
      union {
        float real;
        uint32_t base;
      } u_Ozone_ppm;
      u_Ozone_ppm.real = this->Ozone_ppm;
      *(outbuffer + offset + 0) = (u_Ozone_ppm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Ozone_ppm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Ozone_ppm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Ozone_ppm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Ozone_ppm);
      union {
        float real;
        uint32_t base;
      } u_HCHO_ugm3;
      u_HCHO_ugm3.real = this->HCHO_ugm3;
      *(outbuffer + offset + 0) = (u_HCHO_ugm3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_HCHO_ugm3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_HCHO_ugm3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_HCHO_ugm3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->HCHO_ugm3);
      union {
        float real;
        uint32_t base;
      } u_CO_ppm;
      u_CO_ppm.real = this->CO_ppm;
      *(outbuffer + offset + 0) = (u_CO_ppm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_CO_ppm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_CO_ppm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_CO_ppm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->CO_ppm);
      union {
        float real;
        uint32_t base;
      } u_NO2_ppm;
      u_NO2_ppm.real = this->NO2_ppm;
      *(outbuffer + offset + 0) = (u_NO2_ppm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_NO2_ppm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_NO2_ppm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_NO2_ppm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->NO2_ppm);
      union {
        float real;
        uint32_t base;
      } u_Rn_Bqm3;
      u_Rn_Bqm3.real = this->Rn_Bqm3;
      *(outbuffer + offset + 0) = (u_Rn_Bqm3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Rn_Bqm3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Rn_Bqm3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Rn_Bqm3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Rn_Bqm3);
      union {
        float real;
        uint32_t base;
      } u_TVOCs_ugm3;
      u_TVOCs_ugm3.real = this->TVOCs_ugm3;
      *(outbuffer + offset + 0) = (u_TVOCs_ugm3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_TVOCs_ugm3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_TVOCs_ugm3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_TVOCs_ugm3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->TVOCs_ugm3);
      union {
        float real;
        uint32_t base;
      } u_temp_celcius;
      u_temp_celcius.real = this->temp_celcius;
      *(outbuffer + offset + 0) = (u_temp_celcius.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temp_celcius.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temp_celcius.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temp_celcius.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temp_celcius);
      union {
        float real;
        uint32_t base;
      } u_hum_RHp;
      u_hum_RHp.real = this->hum_RHp;
      *(outbuffer + offset + 0) = (u_hum_RHp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hum_RHp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hum_RHp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hum_RHp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hum_RHp);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_Dust_PM2_5_ugm3;
      u_Dust_PM2_5_ugm3.base = 0;
      u_Dust_PM2_5_ugm3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Dust_PM2_5_ugm3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Dust_PM2_5_ugm3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Dust_PM2_5_ugm3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Dust_PM2_5_ugm3 = u_Dust_PM2_5_ugm3.real;
      offset += sizeof(this->Dust_PM2_5_ugm3);
      union {
        float real;
        uint32_t base;
      } u_Dust_PM10_ugm3;
      u_Dust_PM10_ugm3.base = 0;
      u_Dust_PM10_ugm3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Dust_PM10_ugm3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Dust_PM10_ugm3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Dust_PM10_ugm3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Dust_PM10_ugm3 = u_Dust_PM10_ugm3.real;
      offset += sizeof(this->Dust_PM10_ugm3);
      union {
        float real;
        uint32_t base;
      } u_CO2_ppm;
      u_CO2_ppm.base = 0;
      u_CO2_ppm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_CO2_ppm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_CO2_ppm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_CO2_ppm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->CO2_ppm = u_CO2_ppm.real;
      offset += sizeof(this->CO2_ppm);
      union {
        float real;
        uint32_t base;
      } u_Ozone_ppm;
      u_Ozone_ppm.base = 0;
      u_Ozone_ppm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Ozone_ppm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Ozone_ppm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Ozone_ppm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Ozone_ppm = u_Ozone_ppm.real;
      offset += sizeof(this->Ozone_ppm);
      union {
        float real;
        uint32_t base;
      } u_HCHO_ugm3;
      u_HCHO_ugm3.base = 0;
      u_HCHO_ugm3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_HCHO_ugm3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_HCHO_ugm3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_HCHO_ugm3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->HCHO_ugm3 = u_HCHO_ugm3.real;
      offset += sizeof(this->HCHO_ugm3);
      union {
        float real;
        uint32_t base;
      } u_CO_ppm;
      u_CO_ppm.base = 0;
      u_CO_ppm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_CO_ppm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_CO_ppm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_CO_ppm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->CO_ppm = u_CO_ppm.real;
      offset += sizeof(this->CO_ppm);
      union {
        float real;
        uint32_t base;
      } u_NO2_ppm;
      u_NO2_ppm.base = 0;
      u_NO2_ppm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_NO2_ppm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_NO2_ppm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_NO2_ppm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->NO2_ppm = u_NO2_ppm.real;
      offset += sizeof(this->NO2_ppm);
      union {
        float real;
        uint32_t base;
      } u_Rn_Bqm3;
      u_Rn_Bqm3.base = 0;
      u_Rn_Bqm3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Rn_Bqm3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Rn_Bqm3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Rn_Bqm3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Rn_Bqm3 = u_Rn_Bqm3.real;
      offset += sizeof(this->Rn_Bqm3);
      union {
        float real;
        uint32_t base;
      } u_TVOCs_ugm3;
      u_TVOCs_ugm3.base = 0;
      u_TVOCs_ugm3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_TVOCs_ugm3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_TVOCs_ugm3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_TVOCs_ugm3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->TVOCs_ugm3 = u_TVOCs_ugm3.real;
      offset += sizeof(this->TVOCs_ugm3);
      union {
        float real;
        uint32_t base;
      } u_temp_celcius;
      u_temp_celcius.base = 0;
      u_temp_celcius.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temp_celcius.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temp_celcius.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temp_celcius.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temp_celcius = u_temp_celcius.real;
      offset += sizeof(this->temp_celcius);
      union {
        float real;
        uint32_t base;
      } u_hum_RHp;
      u_hum_RHp.base = 0;
      u_hum_RHp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hum_RHp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hum_RHp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hum_RHp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->hum_RHp = u_hum_RHp.real;
      offset += sizeof(this->hum_RHp);
     return offset;
    }

    const char * getType(){ return "zetabot_main/EnvironmentMsgs"; };
    const char * getMD5(){ return "35d3a34c8dfa110d2f1cdfb07f1501a2"; };

  };

}
#endif