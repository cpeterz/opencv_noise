#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat matrix = cv::Mat::zeros(8, 8, CV_8UC1);
    cv::RNG random_number(2); //随机种子
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            matrix.at<uint8_t>(i, j) = random_number.uniform(0, 255);
            std::cout << (int)matrix.at<uchar>(i, j);
            std::cout << '\t';
        }
        std::cout << "\n";
    }
    cv::Mat matrix2 = matrix.clone();

    //中值滤波操作
    for (int i = 1; i < matrix.rows - 1; i++)
    {
        for (int j = 1; j < matrix.cols - 2; j++)
        {
            matrix.at<uchar>(i, j) = (matrix.at<uchar>(i - 1, j - 1) + matrix.at<uchar>(i - 1, j) +
                                      matrix.at<uchar>(i - 1, j) + matrix.at<uchar>(i, j - 1) + matrix.at<uchar>(i, j) +
                                      matrix.at<uchar>(i, j + 1) + matrix.at<uchar>(i + 1, j - 1) + matrix.at<uchar>(i + 1, j) +
                                      matrix.at<uchar>(i + 1, j + 1)) /
                                     9;
        }
    }

    std::cout << "中值滤波后的矩阵：（边缘未处理）" << std::endl;
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            std::cout << (int)matrix.at<uchar>(i, j);
            std::cout << '\t';
        }
        std::cout << "\n";
    }

    /*cv::Mat sobel = (cv::Mat_<char>(3, 3) << 1, 2, 1,
                     0, 0, 0,
                     -1, -2, -1);
    cv::Mat result_matrix;
    cv::filter2D(matrix,result_matrix,-1,sobel);
    std::cout<<"soble算子处理后的矩阵"<<std::endl;
    for (int i = 0; i < result_matrix.rows; i++)
    {
        for (int j = 0; j < result_matrix.cols; j++)
        {
            std::cout << (int)result_matrix.at<uchar>(i, j);
            std::cout << '\t';
        }
        std::cout << "\n";
    }*/

    // Sobel算子滤波操作
    for (int i = 1; i < matrix2.rows - 1; i++)
    {
        for (int j = 1; j < matrix2.cols - 2; j++)
        {
            matrix.at<uchar>(i, j) = (matrix2.at<uchar>(i - 1, j - 1) + 2 * matrix2.at<uchar>(i - 1, j) +
                                      matrix2.at<uchar>(i - 1, j) - matrix2.at<uchar>(i + 1, j - 1) -
                                      matrix2.at<uchar>(i + 1, j) - 2 * matrix2.at<uchar>(i + 1, j + 1));
        }
    }
    std::cout << "Sobel算子滤波后的矩阵：（边缘未处理）" << std::endl;
    for (int i = 0; i < matrix2.rows; i++)
    {
        for (int j = 0; j < matrix2.cols; j++)
        {
            std::cout << (int)matrix2.at<uchar>(i, j);
            std::cout << '\t';
        }
        std::cout << "\n";
    }

    return 0;
}