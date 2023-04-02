#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <ros/ros.h>
#include <iostream>
#include <vector>

#define MIN_HSVCOLOR cv::Scalar(0, 60, 180)
#define MAX_HSVCOLOR cv::Scalar(10, 160, 240)

using namespace std;

cv::Mat input;
cv::Mat tmp_img;
cv::Mat msk_img, hsv_img, result;


int main(int argc, char** argv)
{
	ros::init(argc, argv, "color_detect");	// ノード名は"color_detect"
	
	input = cv::imread("/home/ubuntu/ros_ren/images/img8.jpg", 1); // 入力画像 

	cv::Size s = input.size();

	tmp_img.create(s, CV_32FC3);
	result.create(s, CV_32FC3);
	msk_img.create(s, CV_8UC1);

	tmp_img = input.clone();

	
	cv::cvtColor(tmp_img, hsv_img, cv::COLOR_BGR2HSV); // 画像の色空間(BGR空間)をHSV空間に変換
	
	cv::inRange(hsv_img, MIN_HSVCOLOR, MAX_HSVCOLOR, msk_img);


	tmp_img = input.clone();
	result = cv::Scalar(0.0, 0.0, 0.0);
	tmp_img.copyTo(result, msk_img);


	cv::imwrite("/tmp/output.jpg", result);
	cv::waitKey(0);

	return 0;
}
