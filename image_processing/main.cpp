#include <image_processing/Util/MyMatrix.hpp>
#include <opencv2/opencv.hpp>
int main()
{
    cv::Mat image = cv::imread("D://downloads//image//1.jpg");
    MyMatrix a = MyMatrix(image);
    cout << a.GetChannels();
    return 0;
}