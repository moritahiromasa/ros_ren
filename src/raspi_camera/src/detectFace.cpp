#include <ros/ros.h>
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	ros::init(argc, argv, "detectFace");



	Mat frame; 
	CascadeClassifier cascade;
	cascade.load("/usr/share/opencv4/haarcascades/haarcascade_frontalface_default.xml");
	vector<Rect> faces;
	
	int error;

	VideoCapture cap(0);
	if(cap.isOpened() == false)
	{		
		cout << "could not find USB camera\n";
		error = -1;
	}
	
	if(error == -1)
	{
		while(1)
		{
			cap >> frame;
			cascade.detectMultiScale(frame, faces, 1.1, 3, 0, Size(20, 20));
			for(int i = 0; i < faces.size(); i++)
			{
				rectangle(frame, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), Scalar(0, 0, 255), 3, CV_AVX);
			}
			imshow("window", frame);

			int key = waitKey(1);
			if(key == 113) // qボタンが押されたとき
			{
				break;
			} // ループを抜ける(終了する)
		}
		
		destroyAllWindows();
	}
	
	return 0;
}
