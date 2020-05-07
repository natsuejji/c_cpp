#include <opencv2/opencv.hpp>
using namespace cv;
int main()
{
    Mat img = imread("D://downloads//image//1.jpg");
    imshow("sirjin", img);
    waitKey(0);
    return 0;
}