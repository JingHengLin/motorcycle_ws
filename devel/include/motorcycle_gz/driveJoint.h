// Generated by gencpp from file motorcycle_gz/driveJoint.msg
// DO NOT EDIT!


#ifndef MOTORCYCLE_GZ_MESSAGE_DRIVEJOINT_H
#define MOTORCYCLE_GZ_MESSAGE_DRIVEJOINT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace motorcycle_gz
{
template <class ContainerAllocator>
struct driveJoint_
{
  typedef driveJoint_<ContainerAllocator> Type;

  driveJoint_()
    : force(0.0)
    , velocity_goal(0.0)
    , velocity_current(0.0)
    , direction(0.0)
    , time(0.0)  {
    }
  driveJoint_(const ContainerAllocator& _alloc)
    : force(0.0)
    , velocity_goal(0.0)
    , velocity_current(0.0)
    , direction(0.0)
    , time(0.0)  {
  (void)_alloc;
    }



   typedef double _force_type;
  _force_type force;

   typedef double _velocity_goal_type;
  _velocity_goal_type velocity_goal;

   typedef double _velocity_current_type;
  _velocity_current_type velocity_current;

   typedef double _direction_type;
  _direction_type direction;

   typedef double _time_type;
  _time_type time;





  typedef boost::shared_ptr< ::motorcycle_gz::driveJoint_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::motorcycle_gz::driveJoint_<ContainerAllocator> const> ConstPtr;

}; // struct driveJoint_

typedef ::motorcycle_gz::driveJoint_<std::allocator<void> > driveJoint;

typedef boost::shared_ptr< ::motorcycle_gz::driveJoint > driveJointPtr;
typedef boost::shared_ptr< ::motorcycle_gz::driveJoint const> driveJointConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::motorcycle_gz::driveJoint_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::motorcycle_gz::driveJoint_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::motorcycle_gz::driveJoint_<ContainerAllocator1> & lhs, const ::motorcycle_gz::driveJoint_<ContainerAllocator2> & rhs)
{
  return lhs.force == rhs.force &&
    lhs.velocity_goal == rhs.velocity_goal &&
    lhs.velocity_current == rhs.velocity_current &&
    lhs.direction == rhs.direction &&
    lhs.time == rhs.time;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::motorcycle_gz::driveJoint_<ContainerAllocator1> & lhs, const ::motorcycle_gz::driveJoint_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace motorcycle_gz

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::motorcycle_gz::driveJoint_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::motorcycle_gz::driveJoint_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::motorcycle_gz::driveJoint_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::motorcycle_gz::driveJoint_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::motorcycle_gz::driveJoint_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::motorcycle_gz::driveJoint_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::motorcycle_gz::driveJoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "84578ee7f01bae230834681aca563918";
  }

  static const char* value(const ::motorcycle_gz::driveJoint_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x84578ee7f01bae23ULL;
  static const uint64_t static_value2 = 0x0834681aca563918ULL;
};

template<class ContainerAllocator>
struct DataType< ::motorcycle_gz::driveJoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "motorcycle_gz/driveJoint";
  }

  static const char* value(const ::motorcycle_gz::driveJoint_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::motorcycle_gz::driveJoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 force\n"
"float64 velocity_goal\n"
"float64 velocity_current\n"
"float64 direction\n"
"float64 time\n"
;
  }

  static const char* value(const ::motorcycle_gz::driveJoint_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::motorcycle_gz::driveJoint_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.force);
      stream.next(m.velocity_goal);
      stream.next(m.velocity_current);
      stream.next(m.direction);
      stream.next(m.time);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct driveJoint_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::motorcycle_gz::driveJoint_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::motorcycle_gz::driveJoint_<ContainerAllocator>& v)
  {
    s << indent << "force: ";
    Printer<double>::stream(s, indent + "  ", v.force);
    s << indent << "velocity_goal: ";
    Printer<double>::stream(s, indent + "  ", v.velocity_goal);
    s << indent << "velocity_current: ";
    Printer<double>::stream(s, indent + "  ", v.velocity_current);
    s << indent << "direction: ";
    Printer<double>::stream(s, indent + "  ", v.direction);
    s << indent << "time: ";
    Printer<double>::stream(s, indent + "  ", v.time);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MOTORCYCLE_GZ_MESSAGE_DRIVEJOINT_H