#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <ros/ros.h>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;



Mat Resize_Process(Mat img)
{
	Mat resize_img;
	resize(img, resize_img, Size(640, 480));
	return resize_img;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "sobel_test"); // ノード名は"raspi_image"
	
	Mat src, dst; //出力画像の行列
	
	Mat img1 = cv::imread("/home/ubuntu/ros_ren/images/img.jpg", 1);//sobel入力画像の行列
	Mat img2 = cv::imread("/home/ubuntu/ros_ren/images/img.jpg", IMREAD_GRAYSCALE);//laplaciab入力画像の行列
	
	if(img1.empty() || img2.empty())
		cerr << "Error:Image file not found." << endl;
	else
		cout << "Image file found." << endl;
	
	img1 = Resize_Process(img1);
	img2 = Resize_Process(img2);

	Sobel(img1, src, -1, 0, 1);
	Laplacian(img2, dst, 0);

	imshow("img", img2);
	imshow("dst", dst);
	imwrite("/home/ubuntu/ros_ren/images/Sobel/output.jpg", src);
	imwrite("/home/ubuntu/ros_ren/images/Laplacian/output.jpg", dst);
	
	waitKey(0);
 
	return 0;
}
