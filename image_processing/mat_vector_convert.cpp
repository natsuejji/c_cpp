#include <opencv2/opencv.hpp>
#include <iostream>
#include <iomanip>

using namespace cv;
using namespace std;
int main()
{
    Mat image = imread("D://downloads//image//1.jpg");
    int rows = image.rows;
    int cols = image.cols;
    int channel = image.channels();

    Mat imagef;
    image.convertTo(imagef, CV_32FC3, 1 / 255.0);

    vector<float> v;
    v = (vector<float>)imagef.reshape(1, 1);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            //channel order BGR
            v[channel * cols * i + channel * j + 0] = 255.0;
            v[channel * cols * i + channel * j + 1] = 0.0;
            v[channel * cols * i + channel * j + 2] = 0.0;
        }
    }

    Mat newImg = Mat(v);
    newImg = newImg.reshape(3, image.rows);

    cv::imshow("test", newImg);
    cv::waitKey(0);
    return 0;
}
