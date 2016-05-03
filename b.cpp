// test5.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
int main(int argc,char* argv[])
{
cv::namedWindow("Control",CV_WINDOW_AUTOSIZE);
cv::VideoCapture cap;
cap.open(0);
cv::Mat img;
if (!cap.isOpened())
 return -2;

int iLowH=0;
int iHighH=179;

int iLowS=0;
int iHighS=255;

int iLowV=0;
int iHighV=255;
// Create Trackbar in Control window
cv::createTrackbar("LowH","Control",&iLowH,179);
cv::createTrackbar("HighH","Control",&iHighH,179);

cv::createTrackbar("LowS","Control",&iLowS,255);
cv::createTrackbar("HighS","Control",&iHighS,255);

cv::createTrackbar("LowV","Control",&iLowV,255);
cv::createTrackbar("HighV","Control",&iHighV,255);

while(true)
{
cv::Mat imgOriginal;
bool bSuccess=cap.read(imgOriginal);

if(!bSuccess)
 break;

cv::Mat imgHSV;
cv::cvtColor(imgOriginal,imgHSV,cv::COLOR_BGR2HSV);
cv::Mat imgThresholded;
cv::inRange(imgHSV,cv::Scalar(iLowH,iLowS,iLowV),cv::Scalar(iHighH,iHighS,iHighV),imgThresholded);

cv::erode(imgThresholded,imgThresholded,cv::getStructuringElement(cv::MORPH_ELLIPSE,cv::Size(5,5)));
cv::dilate(imgThresholded,imgThresholded,cv::getStructuringElement(cv::MORPH_ELLIPSE,cv::Size(5,5)));

cv::dilate(imgThresholded,imgThresholded,cv::getStructuringElement(cv::MORPH_ELLIPSE,cv::Size(5,5)));
cv::erode(imgThresholded,imgThresholded,cv::getStructuringElement(cv::MORPH_ELLIPSE,cv::Size(5,5)));
cv::imshow("Thresholded Image",imgThresholded);
cv::imshow("Original",imgOriginal);

if(cv::waitKey(30)>=0)
 break;


}

return 0;
}
