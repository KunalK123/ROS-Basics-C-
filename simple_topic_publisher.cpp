#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <std_msgs/Int32.h>

int main(int argc, char **argv) {

  ros::init(argc, argv, "topic_publisher");
  ros::NodeHandle nh;

  ros::Publisher pub1 =
      nh.advertise<std_msgs::Int32>("counter", 1000); // for exercise 2.1
  // ros::Publisher pub2 = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1); //
  // for exercise 2.2
  ros::Rate loop_rate(2);

  std_msgs::Int32 count; // for exercise 2.1
  count.data = 0;        // for exercise 2.1
  // geometry_msgs::Twist var;    // for exercise 2.2
  // var.linear.x = 0.5;  // for exercise 2.2
  // var.angular.z = 0.5; // for exercise 2.2
  // while (ros::ok()) {  // for exercise 2.2
  // pub2.publish(var);   // for exercise 2.2
  // loop_rate.sleep();   // for exercise 2.2
  // }    // for exercise 2.2

  while (ros::ok()) {    // for exercise 2.1
    pub1.publish(count); // for exercise 2.1
    ros::spinOnce();     // for exercise 2.1
    loop_rate.sleep();   // for exercise 2.1
    ++count.data;        // for exercise 2.1
  }                      // for exercise 2.1

  return 0;
}
