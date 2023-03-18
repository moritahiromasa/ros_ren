#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <vector>

using namespace cv;
using namespace std;

int main()
{
	CascadeClassifier cascade;
	cascade.load("/home/ubuntu/Downloads/opencv/data/haarcascade_frontalface_default.xml"); // 正面顔情報が入っているカスケードファイル読み込み
	
	Mat img = imread("~/Pictures/photo.png", IMREAD_UNCHANGED); // 入力画像読み込み
	vector<Rect> faces; // 輪郭情報を格納場所
	cascade.detectMultiScale(img, faces, 1.1, 3, 0, Size(20, 20)); // カスケードファイルに基づいて顔を検知する. 検知した顔情報をベクトルfacesに格納
	
	for(int i = 0; i < faces.size(); i++){
		rectangle(img, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), Scalar(0, 0, 255), 3, CV_AVX); //検出した顔を赤色矩形で囲む CV_AVX
	}

	imshow("detect face", img);
	waitKey(0);
}

