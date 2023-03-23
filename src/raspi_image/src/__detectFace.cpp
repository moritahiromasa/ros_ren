#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <sensor_msgs/Image.h>
#include <ros/ros.h>
#include <iostream>
#include <vector>

using namespace std;
//using namespace cv;


class ImagePublisher {
public:
	ros::NodeHandle nh_;
	ros::Publisher imagePub_;
	std::string imagePath_;

	ImagePublisher(void):
		nh_("~"),
		imagePath_("/home/ubuntu/ros_ren/images/")
		{
			imagePub_ = nh_.advertise<sensor_msgs::Image>("/raspi_image", 1);
		}
	
	void spin(void)
	{
		ros::Rate loopRate(1); // 1Hz

		for(int i = 1; i <= 7; i++)
		{ 
			string imageFileName = imagePath_ + "img" + to_string(i) + ".jpg";
//			printf("imageFile=%s\n", imageFileName.c_str());
			
			cv::Mat img = cv::imread( imageFileName.c_str() , 1); //カラーで読み込み
		}
	}
};


int main(int argc, char **argv)
{
	ros::init(argc, argv, "raspi_image"); // ノード名は"raspi_image"
	
	cv::CascadeClassifier cascade_classifier; // 
	cascade_classifier.load("/usr/share/opencv4/haarcascades/haarcascade_frontalface_default.xml"); // カスケードファイルの読み込み
	

	// カスケードファイルが読み込まれているか確認
	if(cascade_classifier.empty())
		cerr << "Error:cascade file not found" << endl;
	else
		cout << "cascade file found" << endl;
	

	ImagePublisher publisher;
	publisher.spin(); // 6枚分画像が読み込めているか確認

	cv::Mat img = cv::imread("/home/ubuntu/ros_ren/images/photo.png", 1); //カラーで読み込み
	
	
		

	vector<cv::Rect> faces; // 輪郭情報を格納する場所
	// カスケードに基づいて顔を検出している
	cascade_classifier.detectMultiScale(img, faces, 1.1, 3, 0,cv::Size(20, 20));
/*
	image:        img			--->
	objects:      faces			--->
	scaleFactor:  2.0			--->
	minNeighbers: 3				--->
	int flag: 	  0				---> もう使われないらしいけど、引数を減らすとエラーになる
	minSize:      Size(20, 20)	--->
*/	
	for(int i = 0; i < faces.size(); i++)
		rectangle(img,
				cv::Point(faces[i].x, faces[i].y),
				cv::Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height),
				cv::Scalar(0, 255, 255),
				4
		);
/***	rectangleの引数

	img:	画像の変数
	cv::Point(左上の点のx座標, 左上の点のy座標)
	cv::Point(左下の点のx座標, 左下の点のy座標)
	cv::Scale(青, 緑, 赤)
	線の太さ
*/
	imwrite("/tmp/output.png", img);	// 画像を保存
	cv::waitKey(0); // キーボードが押されるまで処理を待つ

	return 0;

}
