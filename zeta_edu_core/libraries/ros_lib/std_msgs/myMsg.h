#ifndef _ROS_std_msgs_myMsg_h
#define _ROS_std_msgs_myMsg_h

#include <stdint.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace std_msgs
{

  class myMsg : public ros::Msg
  {
    public:
      typedef bool _LED_ON_t;
      _LED_ON_t LED_ON;
      typedef char _LED_Color_t;
      _LED_Color_t LED_Color;
      typedef bool _Pulifier_ON_t;
      _Pulifier_ON_t Pulifier_ON;
      typedef uint8_t _Pulifier_Level_t;
      _Pulifier_Level_t Pulifier_Level;
      typedef bool _UVC_ON_t;
      _UVC_ON_t UVC_ON;
      typedef bool _Solenoid_ON_t;
      _Solenoid_ON_t Solenoid_ON;
      typedef bool _Booster_ON_t;
      _Booster_ON_t Booster_ON;

    myMsg():
      LED_ON(false),
      LED_Color('\0'),
      Pulifier_ON(false),
      Pulifier_Level(0),
      UVC_ON(false),
      Solenoid_ON(false),
      Booster_ON(false)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ledon;
      u_ledon.real = this->LED_ON;
      *(outbuffer + offset + 0) = (u_ledon.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->LED_ON);
      union {
        char real;
        uint8_t base;
      } u_ledcolor;
      u_ledcolor.real = this->LED_Color;
      *(outbuffer + offset + 0) = (u_ledcolor.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->LED_Color);
      union {
        bool real;
        uint8_t base;
      } u_pulifieron;
      u_pulifieron.real = this->Pulifier_ON;
      *(outbuffer + offset + 0) = (u_pulifieron.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Pulifier_ON);
      union {
        float real;
        uint8_t base;
      } u_pulifierlevel;
      u_pulifierlevel.real = this->Pulifier_Level;
      *(outbuffer + offset + 0) = (u_pulifierlevel.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Pulifier_Level);
      union {
        bool real;
        uint8_t base;
      } u_uvcon;
      u_uvcon.real = this->UVC_ON;
      *(outbuffer + offset + 0) = (u_uvcon.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->UVC_ON);
      union {
        bool real;
        uint8_t base;
      } u_solenoion;
      u_solenoion.real = this->Solenoid_ON;
      *(outbuffer + offset + 0) = (u_solenoion.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Solenoid_ON);
      union {
        bool real;
        uint8_t base;
      } u_pulifieron;
      u_boosteron.real = this->Booster_ON;
      *(outbuffer + offset + 0) = (u_boosteron.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Booster_ON);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {

      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ledon;
      u_ledon.real = this->LED_ON;
      *(outbuffer + offset + 0) = (u_ledon.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->LED_ON);
      union {
        char real;
        uint8_t base;
      } u_ledcolor;
      u_ledcolor.real = this->LED_Color;
      *(outbuffer + offset + 0) = (u_ledcolor.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->LED_Color);
      union {
        bool real;
        uint8_t base;
      } u_pulifieron;
      u_pulifieron.real = this->Pulifier_ON;
      *(outbuffer + offset + 0) = (u_pulifieron.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Pulifier_ON);
      union {
        float real;
        uint8_t base;
      } u_pulifierlevel;
      u_pulifierlevel.real = this->Pulifier_Level;
      *(outbuffer + offset + 0) = (u_pulifierlevel.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Pulifier_Level);
      union {
        bool real;
        uint8_t base;
      } u_uvcon;
      u_uvcon.real = this->UVC_ON;
      *(outbuffer + offset + 0) = (u_uvcon.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->UVC_ON);
      union {
        bool real;
        uint8_t base;
      } u_solenoion;
      u_solenoion.real = this->Solenoid_ON;
      *(outbuffer + offset + 0) = (u_solenoion.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Solenoid_ON);
      union {
        bool real;
        uint8_t base;
      } u_pulifieron;
      u_boosteron.real = this->Booster_ON;
      *(outbuffer + offset + 0) = (u_boosteron.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Booster_ON);


      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_r;
      u_r.base = 0;
      u_r.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_r.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_r.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_r.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->r = u_r.real;
      offset += sizeof(this->r);
      union {
        float real;
        uint32_t base;
      } u_g;
      u_g.base = 0;
      u_g.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_g.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_g.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_g.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->g = u_g.real;
      offset += sizeof(this->g);
      union {
        float real;
        uint32_t base;
      } u_b;
      u_b.base = 0;
      u_b.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_b.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_b.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_b.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->b = u_b.real;
      offset += sizeof(this->b);
      union {
        float real;
        uint32_t base;
      } u_a;
      u_a.base = 0;
      u_a.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_a.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_a.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_a.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->a = u_a.real;
      offset += sizeof(this->a);
     return offset;
    }

    const char * getType(){ return "std_msgs/ColorRGBA"; };
    const char * getMD5(){ return "a29a96539573343b1310c73607334b00"; };

  };

}
#endif
