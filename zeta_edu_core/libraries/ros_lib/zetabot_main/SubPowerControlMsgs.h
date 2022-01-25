#ifndef _ROS_zetabot_main_SubPowerControlMsgs_h
#define _ROS_zetabot_main_SubPowerControlMsgs_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace zetabot_main
{

  class SubPowerControlMsgs : public ros::Msg
  {
    public:
      bool on[8];

    SubPowerControlMsgs():
      on()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 8; i++){
      union {
        bool real;
        uint8_t base;
      } u_oni;
      u_oni.real = this->on[i];
      *(outbuffer + offset + 0) = (u_oni.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->on[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint32_t i = 0; i < 8; i++){
      union {
        bool real;
        uint8_t base;
      } u_oni;
      u_oni.base = 0;
      u_oni.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->on[i] = u_oni.real;
      offset += sizeof(this->on[i]);
      }
     return offset;
    }

    const char * getType(){ return "zetabot_main/SubPowerControlMsgs"; };
    const char * getMD5(){ return "3b19e8e4e9fe14ce9093ae30dce9d8d7"; };

  };

}
#endif