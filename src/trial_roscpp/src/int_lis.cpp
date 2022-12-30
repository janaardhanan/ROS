#include "ros/ros.h"
#include "std_msgs/Int32.h"


void Callback(const std_msgs::Int32::ConstPtr& msg)
{
  ROS_INFO("I heard: [%d]", msg->data);
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "int_listener");


  ros::NodeHandle nh;


  ros::Subscriber sub = nh.subscribe("INT", 1000, Callback);

  ros::spin();

  return 0;
}