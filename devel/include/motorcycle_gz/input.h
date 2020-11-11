// Generated by gencpp from file motorcycle_gz/input.msg
// DO NOT EDIT!


#ifndef MOTORCYCLE_GZ_MESSAGE_INPUT_H
#define MOTORCYCLE_GZ_MESSAGE_INPUT_H


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
struct input_
{
  typedef input_<ContainerAllocator> Type;

  input_()
    : x(0)
    , y(0)  {
    }
  input_(const ContainerAllocator& _alloc)
    : x(0)
    , y(0)  {
  (void)_alloc;
    }



   typedef int32_t _x_type;
  _x_type x;

   typedef int32_t _y_type;
  _y_type y;





  typedef boost::shared_ptr< ::motorcycle_gz::input_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::motorcycle_gz::input_<ContainerAllocator> const> ConstPtr;

}; // struct input_

typedef ::motorcycle_gz::input_<std::allocator<void> > input;

typedef boost::shared_ptr< ::motorcycle_gz::input > inputPtr;
typedef boost::shared_ptr< ::motorcycle_gz::input const> inputConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::motorcycle_gz::input_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::motorcycle_gz::input_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::motorcycle_gz::input_<ContainerAllocator1> & lhs, const ::motorcycle_gz::input_<ContainerAllocator2> & rhs)
{
  return lhs.x == rhs.x &&
    lhs.y == rhs.y;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::motorcycle_gz::input_<ContainerAllocator1> & lhs, const ::motorcycle_gz::input_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace motorcycle_gz

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::motorcycle_gz::input_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::motorcycle_gz::input_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::motorcycle_gz::input_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::motorcycle_gz::input_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::motorcycle_gz::input_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::motorcycle_gz::input_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::motorcycle_gz::input_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bd7b43fd41d4c47bf5c703cc7d016709";
  }

  static const char* value(const ::motorcycle_gz::input_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xbd7b43fd41d4c47bULL;
  static const uint64_t static_value2 = 0xf5c703cc7d016709ULL;
};

template<class ContainerAllocator>
struct DataType< ::motorcycle_gz::input_<ContainerAllocator> >
{
  static const char* value()
  {
    return "motorcycle_gz/input";
  }

  static const char* value(const ::motorcycle_gz::input_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::motorcycle_gz::input_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 x\n"
"int32 y\n"
;
  }

  static const char* value(const ::motorcycle_gz::input_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::motorcycle_gz::input_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct input_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::motorcycle_gz::input_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::motorcycle_gz::input_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<int32_t>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<int32_t>::stream(s, indent + "  ", v.y);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MOTORCYCLE_GZ_MESSAGE_INPUT_H
