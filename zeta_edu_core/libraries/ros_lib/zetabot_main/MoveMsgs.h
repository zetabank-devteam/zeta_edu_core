#ifndef _ROS_zetabot_main_MoveMsgs_h
#define _ROS_zetabot_main_MoveMsgs_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace zetabot_main
{

  class MoveMsgs : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _linear_x_type;
      _linear_x_type linear_x;
      typedef float _angular_z_type;
      _angular_z_type angular_z;

    MoveMsgs():
      header(),
      linear_x(0),
      angular_z(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->linear_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->angular_z);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->linear_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angular_z));
     return offset;
    }

    const char * getType(){ return "zetabot_main/MoveMsgs"; };
    const char * getMD5(){ return "5702ac013c23799a0863e4be97fe7e69"; };

  };

}
#endif