#include "main.h"

int main(int argc,char** argv)
{

	std::cout<<"start"<<std::endl;
	//f30
	cv::VideoCapture cap(0);
	if(!cap.isOpened()) 
	{
		std::cout<<"nonono"<<std::endl;
		return -1;
	}
	while(1){

		//kinect
		v.GetRGB_D();
		v.createImg();

		//kinect
		cv::imshow("color", v.getRGBImg());
		cv::imshow("depth", v.getDPTImg());

		//f30
		cv::Mat frame;
		cap >> frame; 
		cv::imshow("Capture",frame); 

		int key=cv::waitKey(1);

		keyCheck(frame,key);
	}
	return 0;

}

void keyCheck(cv::Mat src,int key)
{
	switch(key){
	case 'q':
		exit(0);
		break;
	case '\033':
		exit(0);
		break;
	case 's':

		//kinect
		v.saveRGBImg("./color");
		v.saveDPTImg("./depth");

		//f30
		char filename[30];
		sprintf(filename,"thermal.bmp");
		cv::imwrite(filename,src);
		break;
	}
}
