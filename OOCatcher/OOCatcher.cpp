// OOCatcher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat canvas = Mat::zeros(1800,1800, CV_8UC3);
    line(canvas,
        Point(500, 300),
        Point(500, 700),
        Scalar(250, 250, 250),
        2,
        LINE_8);
   // imwrite("Line.png", canvas);
   // cout << "aaaa";
}

