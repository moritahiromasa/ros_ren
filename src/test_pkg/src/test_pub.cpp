#include <ros/ros.h>
#include <std_msgs/Header.h>


int main(int argc, char **argv)
{
    ros::init(argc, argv, "test_pub");
    ros::NodeHandle nh("~");
    ros::Publisher headerPub = nh.advertise<std_msgs::Header>("/test_msg", 1);
    ros::Rate loopRate(10.0);

    while (ros::ok())
	{
        ros::spinOnce();
        
		std_msgs::Header header;
        header.stamp = ros::Time::now();

        headerPub.publish(header);
        printf("Publish time is %lf\n", header.stamp.toSec());

        loopRate.sleep();
    }

    return 0;
}
