
//儲存矩陣資料用
#ifndef MYMATRIX_H
#define MYMATRIX_H

#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
using namespace std;

class MyMatrix
{
private:
    /* data */
    int rows;
    int cols;
    int channels;
    vector<float> data;

public:
    //constructor
    MyMatrix(cv::Mat input);
    MyMatrix(int rows, int cols, int channels);
    MyMatrix(const MyMatrix &copy);
    //destructor
    ~MyMatrix();

    //隨機初始化陣列
    void RandomInitData();
    //轉出mat
    cv::Mat VToMat();

    //data
    vector<float> GetData();
    //直接讀取影像
    void SetData(string imagePath);
    //使用mat作為輸入
    void SetData(cv::Mat input);
    //使用外來vec作為輸入
    void SetData(vector<float> data, int rows, int cols);
    //Rows
    int GetRows();
    //Cols
    int GetCols();
    //channels
    int GetChannels();
};
//constructor
MyMatrix::MyMatrix(cv::Mat input)
{
    this->SetData(input);
}

MyMatrix::MyMatrix(int rows, int cols, int channels)
{
    this->rows = rows;
    this->cols = cols;
    this->channels = channels;
    this->RandomInitData();
}

MyMatrix::MyMatrix(const MyMatrix &copy)
{
    this->rows = copy.rows;
    this->cols = copy.cols;
    this->channels = copy.channels;
    for (int i = 0; i < this->rows * this->cols * this->channels; i++)
    {
        this->data[i] = copy.data[i];
    }
}
//destructor
MyMatrix::~MyMatrix()
{
    data.clear();
}
#endif