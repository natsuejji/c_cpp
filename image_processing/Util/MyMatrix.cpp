#include <MyMatrix.hpp>
//隨機初始化陣列
void MyMatrix::RandomInitData()
{
    for (auto i : this->data)
    {
        i = (float)rand() / (RAND_MAX + 1.0);
    }
}
//轉出mat
cv::Mat MyMatrix::VToMat()
{
    cv::Mat n = cv::Mat(this->data);
    return n.reshape(this->channels, this->rows);
}
//data
vector<float> MyMatrix::GetData()
{
    return this->data;
}
//使用外來cv::mat作為輸入
void MyMatrix::SetData(cv::Mat input)
{
    int rows = input.rows;
    int cols = input.cols;
    int channel = input.channels();
    cv::Mat imagef;
    input.convertTo(imagef, CV_32FC3, 1 / 255.0);
    this->data = (vector<float>)imagef.reshape(1, 1);
}

void MyMatrix::SetData(string imagePath)
{
    cv::Mat image = cv::imread(imagePath);
    int rows = image.rows;
    int cols = image.cols;
    int channel = image.channels();
    cv::Mat imagef;
    image.convertTo(imagef, CV_32FC3, 1 / 255.0);
    this->data = (vector<float>)imagef.reshape(1, 1);
}
//設定外來vector為data
void MyMatrix::SetData(vector<float> data, int rows, int cols)
{
    this->data = data;
    this->rows = rows;
    this->cols = cols;
}
//Rows
int MyMatrix::GetRows()
{
    return this->rows;
}
//Cols
int MyMatrix::GetCols()
{
    return this->cols;
}
//channels
int MyMatrix::GetChannels()
{
    return this->channels;
}