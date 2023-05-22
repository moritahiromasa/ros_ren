#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <ros/ros.h>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;


int main(int argc, char **argv)
{
	ros::init(argc, argv, "sobel_test"); // ノード名は"raspi_image"
	
	cv::Mat src, dst; //出力画像の行列
	
	cv::Mat img1 = cv::imread("/home/ubuntu/ros_ren/images/img.jpg", 1);//sobel入力画像の行列
	cv::Mat img2 = cv::imread("/home/ubuntu/ros_ren/images/img.jpg", IMREAD_GRAYSCALE);//laplaciab入力画像の行列
	
	if(img1.empty() || img2.empty())
		cerr << "Error:Image file not found." << endl;
	else
		cout << "Image file found." << endl;
	
	Sobel(img1, src, -1, 0, 1);
	Laplacian(img2, dst, 0);

	imshow("img", img2);
	imshow("dst", dst);
	imwrite("/home/ubuntu/ros_ren/images/Sobel/output.jpg", src);
	imwrite("/home/ubuntu/ros_ren/images/Laplacian/output.jpg", dst);
	
	waitKey(0);
 
	return 0;
}
