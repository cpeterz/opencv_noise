#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>
#include<iostream>

int main()
{
    cv::Mat img = cv::imread("/home/peter/OpenCV_test/jiaoyan/jy_picture.png");
    
    if(img.empty())
    {
        printf("未能读取到图像...");
        return -1;
    }
    cv::namedWindow("原图",CV_WINDOW_AUTOSIZE);
    cv::imshow("原图",img);
    
    cv::Mat rect_3_img;
    cv::Mat structureElement = cv::getStructuringElement(cv::MORPH_RECT,cv::Size(3,3));
    cv::morphologyEx(img,rect_3_img,cv::MORPH_CLOSE,structureElement);
    cv::morphologyEx(rect_3_img,rect_3_img,cv::MORPH_OPEN,structureElement);
    cv::namedWindow("rect_3_img",CV_WINDOW_AUTOSIZE);
    cv::imshow("rect_3_img",rect_3_img);

    cv::Mat rect_5_img;
    cv::Mat structureElement2 = cv::getStructuringElement(cv::MORPH_RECT,cv::Size(5,5));
    cv::morphologyEx(img,rect_5_img,cv::MORPH_CLOSE,structureElement2);
    cv::morphologyEx(rect_5_img,rect_5_img,cv::MORPH_OPEN,structureElement2);
    cv::namedWindow("rect_5_img",CV_WINDOW_AUTOSIZE);
    cv::imshow("rect_5_img",rect_5_img);
    
    
    cv::Mat rect_99_img;
    cv::Mat structureElement3 = cv::getStructuringElement(cv::MORPH_RECT,cv::Size(99,99));
    cv::morphologyEx(img,rect_99_img,cv::MORPH_CLOSE,structureElement3);
    cv::morphologyEx(rect_99_img,rect_99_img,cv::MORPH_OPEN,structureElement3);
    cv::namedWindow("rect_99_img",CV_WINDOW_AUTOSIZE);
    cv::imshow("rect_99_img",rect_99_img);

    cv::Mat cross_3_img;
    cv::Mat structureElement4 = cv::getStructuringElement(cv::MORPH_CROSS,cv::Size(3,3));
    cv::morphologyEx(img,cross_3_img,cv::MORPH_CLOSE,structureElement4);
    cv::morphologyEx(cross_3_img,cross_3_img,cv::MORPH_OPEN,structureElement4);
    cv::namedWindow("cross_3_img",CV_WINDOW_AUTOSIZE);
    cv::imshow("cross_3_img",cross_3_img);

    
    cv::Mat cross_15_img;
    cv::Mat structureElement5 = cv::getStructuringElement(cv::MORPH_CROSS,cv::Size(15,15));
    cv::morphologyEx(img,cross_15_img,cv::MORPH_CLOSE,structureElement5);
    cv::morphologyEx(cross_15_img,cross_15_img,cv::MORPH_OPEN,structureElement5);
    cv::namedWindow("cross_15_img",CV_WINDOW_AUTOSIZE);
    cv::imshow("cross_15_img",cross_15_img);

    cv::waitKey(0);

}