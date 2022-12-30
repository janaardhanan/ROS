#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"
#include <sstream>
#include <string>


int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");

  ros::NodeHandle nh;

  ros::Publisher string_pub = nh.advertise<std_msgs::String>("chatter", 1000);
  ros::Publisher int_pub= nh.advertise<std_msgs::Int32>("INT", 1000);

  ros::Rate loop_rate(10);

 int count=1;

  while (ros::ok())
  {
    
    std_msgs::String msg;
    std_msgs::Int32 int_msg;
    std::stringstream ss;

    // std::cout<<"encoder value: "<<encoder<<"\n";
    // ROS_INFO("Encoder: %s\n",encoder.c_str());

    ss << "Hello " << count;

    msg.data = ss.str();
    int_msg.data= count;

    // ROS_INFO("%s", msg.data.c_str());

    string_pub.publish(msg);
    int_pub.publish(int_msg);

    ros::spinOnce();

    loop_rate.sleep();
    count++;
  }

  return 0;
}