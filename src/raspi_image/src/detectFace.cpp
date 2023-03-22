#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "ros/ros.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	ros::init(argc, argv, "raspi_image");
	bool img = cv::imwrite("/home/ubuntu/ros_ren/images/idphoto.jpg", 1); //カラーで読み込み
	cout << "img:" << img << "\n";
	return 0;

}
