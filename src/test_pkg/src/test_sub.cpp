#include <ros/ros.h>
#include <std_msgs/Header.h>

void headerCB(const std_msgs::Header::ConstPtr &msg) 
{
    printf("Subscribe time is %lf\n", msg->stamp.toSec());
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "test_sub");
    ros::NodeHandle nh("~");
    ros::Subscriber headerSub = nh.subscribe("/test_msg", 1, headerCB);
    ros::spin();

    return 0;
}
