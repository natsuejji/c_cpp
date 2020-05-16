#include <opencv2/opencv.hpp>
#include <iostream>
#include <iomanip>

using namespace cv;
using namespace std;
int main()
{
    Mat image = imread("D://downloads//image//1.jpg");

    cv::imshow("test", image);
    cv::waitKey(0);
    return 0;
}
