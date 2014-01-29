#include <iostream>
#include "opencv2\core\core.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\imgproc\imgproc.hpp"

using namespace cv;
using namespace std;

Mat loadImage()
{
	Mat image=imread("lena.png");
	if(!image.data)
	{
		cout<<"no data";
		return image;
	}
	cout<<image.size().width<<","<<image.size().height<<endl;
	namedWindow("original");
	imshow("original",image);
	waitKey(0);
	return image;

}


void colorReduce(Mat &image,int div=64)
{
	Mat colred;
	image.copyTo(colred);

	int nl=colred.rows;//no of lines
	int nc=colred.cols*colred.channels();
	for(int j=0;j<nl;j++)
	{
		//get the address of row j
		uchar* data=colred.ptr<uchar>(j);

		for (int i=0;i<nc;i++)
		{
			//process each pixel
			data[i]=data[i]/div*div+div/2;
			//end of pixel processing
		}
	}
	namedWindow("changed");
	imshow("changed",colred);
	waitKey(0);
}
int main()
{Mat image=loadImage();
namedWindow("original");
	imshow("original",image);
	colorReduce(image,64);
	return 0;
}