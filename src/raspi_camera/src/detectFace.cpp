#include <ros/ros.h>
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

// using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

	ros::init(argc, argv, "raspi_camera");

	cv::Mat frame; 
	cv::CascadeClassifier cascade_classifier;
	cascade_classifier.load("/usr/share/opencv4/haarcascades/haarcascade_frontalface_default.xml");
	
	// カスケードが読み込まれているか確認
	if(cascade_classifier.empty())
		cerr << "Error:cascade file not found" << endl;
	else
		cout << "cascade file found" << endl;
	

	vector<cv::Rect> faces; // 輪郭情報を格納する場所
	

	cv::VideoCapture cap(0); // /dev/video0を使う

	if(!cap.isOpened())
		cerr << "could not find USB camera" << endl;
	else
	{
		cout << "could find USB camera" << endl;

		cv::Mat edges;
		while(1)
		{
			cap >> frame;
			cascade_classifier.detectMultiScale(frame, faces, 1.1, 3, 0, cv::Size(20, 20));
			for(int i = 0; i < faces.size(); i++)
			{
				rectangle(frame, 
						cv::Point(faces[i].x, faces[i].y), 
						cv::Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), 
						cv::Scalar(0, 0, 255), 
						4);
				imwrite("/tmp/output.jpg", frame);
			}

			
			int key = cv::waitKey(1);
			if(key == 113) // qボタンが押されたとき
			{
				break;
			} // ループを抜ける(終了する)
		}
		
	}

	return 0;
}
