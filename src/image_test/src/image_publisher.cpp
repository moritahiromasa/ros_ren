#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <iostream>

//using namespace ros;
//using namespace sensor_msgs;
using namespace std;

class ImagePublisher {
public:
	ros::NodeHandle nh_;
	ros::Publisher imagePub_;
	std::string imageDir_;

	ImagePublisher(void):
		nh_("~"),
		imageDir_("/home/ubuntu/ros_ren/images/")
		{
			imagePub_ = nh_.advertise<sensor_msgs::Image>("/image_test", 1); //パッケージ名
		}



	void spin(void)
	{
		ros::Rate loopRate(1);
		int imageIdx = 0;
		while (ros::ok()) {
			ros::spinOnce();

			std::string imageFileName = imageDir_ + std::to_string(imageIdx) + ".jpg";
			printf("imageFileName=%s\n", imageFileName.c_str());
	
/*			imageIdx++;
			if (imageIdx >= 4)
				imageIdx = 0;
*/
			loopRate.sleep();	
		}
	}
};


int main(int argc, char **argv)
{
	ros::init(argc, argv, "image_publisher"); //ノード名
	ImagePublisher publisher;
	publisher.spin();

	return 0;

}


