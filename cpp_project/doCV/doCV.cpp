#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
	string filePath = "./Resources/testVideo.mp4";
	VideoCapture cap = VideoCapture(filePath);

	printf("%s", filePath.c_str());

	// file check
	if (!cap.isOpened()) {
		printf("\nCan't open the video\n");
		return -1;
	}

	Mat frame;
	Mat gray;
	int k;

	while (true)
	{
		cap.read(frame);
		cvtColor(frame, gray, COLOR_BGR2GRAY);

		// stop requiremets 
		k = waitKey(1) & 0xff;
		if ((k == 27) || (k == 'q') || frame.empty())
		{
			break;
		}

		// image show
		imshow("gray", gray);
	}
	
	destroyAllWindows();
	return 0;
}