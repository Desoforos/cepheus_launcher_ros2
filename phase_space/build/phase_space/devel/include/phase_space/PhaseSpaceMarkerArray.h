// Generated by gencpp from file phase_space/PhaseSpaceMarkerArray.msg
// DO NOT EDIT!


#ifndef PHASE_SPACE_MESSAGE_PHASESPACEMARKERARRAY_H
#define PHASE_SPACE_MESSAGE_PHASESPACEMARKERARRAY_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <phase_space/PhaseSpaceMarker.h>

namespace phase_space
{
template <class ContainerAllocator>
struct PhaseSpaceMarkerArray_
{
  typedef PhaseSpaceMarkerArray_<ContainerAllocator> Type;

  PhaseSpaceMarkerArray_()
    : header()
    , markers()  {
    }
  PhaseSpaceMarkerArray_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , markers(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::msg::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector< ::phase_space::PhaseSpaceMarker_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::phase_space::PhaseSpaceMarker_<ContainerAllocator> >::other >  _markers_type;
  _markers_type markers;





  typedef std::shared_ptr< ::phase_space::PhaseSpaceMarkerArray_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::phase_space::PhaseSpaceMarkerArray_<ContainerAllocator> const> ConstPtr;

}; // struct PhaseSpaceMarkerArray_

typedef ::phase_space::PhaseSpaceMarkerArray_<std::allocator<void> > PhaseSpaceMarkerArray;

typedef std::shared_ptr< ::phase_space::PhaseSpaceMarkerArray > PhaseSpaceMarkerArrayPtr;
typedef std::shared_ptr< ::phase_space::PhaseSpaceMarkerArray const> PhaseSpaceMarkerArrayConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::phase_space::PhaseSpaceMarkerArray_<ContainerAllocator> & v)
{
rclcpp::message_operations::Printer< ::phase_space::PhaseSpaceMarkerArray_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace phase_space

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'phase_space': ['/home/nikiforos/cloned_cepheus_ws/phase_space/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'visualization_msgs': ['/opt/ros/kinetic/share/visualization_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::phase_space::PhaseSpaceMarkerArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::phase_space::PhaseSpaceMarkerArray_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::phase_space::PhaseSpaceMarkerArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::phase_space::PhaseSpaceMarkerArray_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::phase_space::PhaseSpaceMarkerArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::phase_space::PhaseSpaceMarkerArray_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::phase_space::PhaseSpaceMarkerArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2136803090aba6d661b5d51b2df5a97c";
  }

  static const char* value(const ::phase_space::PhaseSpaceMarkerArray_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2136803090aba6d6ULL;
  static const uint64_t static_value2 = 0x61b5d51b2df5a97cULL;
};

template<class ContainerAllocator>
struct DataType< ::phase_space::PhaseSpaceMarkerArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "phase_space/PhaseSpaceMarkerArray";
  }

  static const char* value(const ::phase_space::PhaseSpaceMarkerArray_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::phase_space::PhaseSpaceMarkerArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# An array of phase space markers with a header for global reference\n\
\n\
std_msgs/Header header\n\
phase_space/PhaseSpaceMarker[] markers\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: phase_space/PhaseSpaceMarker\n\
# a phase space marker\n\
\n\
# LED id\n\
int64 id\n\
\n\
# 3D coordinates of the LED\n\
geometry_msgs/Point point\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const ::phase_space::PhaseSpaceMarkerArray_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::phase_space::PhaseSpaceMarkerArray_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.markers);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PhaseSpaceMarkerArray_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::phase_space::PhaseSpaceMarkerArray_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::phase_space::PhaseSpaceMarkerArray_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::msg::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "markers[]" << std::endl;
    for (size_t i = 0; i < v.markers.size(); ++i)
    {
      s << indent << "  markers[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::phase_space::PhaseSpaceMarker_<ContainerAllocator> >::stream(s, indent + "    ", v.markers[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // PHASE_SPACE_MESSAGE_PHASESPACEMARKERARRAY_H
