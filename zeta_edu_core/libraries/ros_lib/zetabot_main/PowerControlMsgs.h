#ifndef _ROS_zetabot_main_PowerControlMsgs_h
#define _ROS_zetabot_main_PowerControlMsgs_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace zetabot_main
{

  class PowerControlMsgs : public ros::Msg
  {
    public:
      typedef int16_t _port_type;
      _port_type port;
      typedef bool _state_type;
      _state_type state;

    PowerControlMsgs():
      port(0),
      state(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_port;
      u_port.real = this->port;
      *(outbuffer + offset + 0) = (u_port.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_port.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->port);
      union {
        bool real;
        uint8_t base;
      } u_state;
      u_state.real = this->state;
      *(outbuffer + offset + 0) = (u_state.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_port;
      u_port.base = 0;
      u_port.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_port.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->port = u_port.real;
      offset += sizeof(this->port);
      union {
        bool real;
        uint8_t base;
      } u_state;
      u_state.base = 0;
      u_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->state = u_state.real;
      offset += sizeof(this->state);
     return offset;
    }

    const char * getType(){ return "zetabot_main/PowerControlMsgs"; };
    const char * getMD5(){ return "749d2559d9da6c7d6daeaa3e50049c2f"; };

  };

}
#endif