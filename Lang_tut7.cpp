#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>

int main(){
    cv::Mat img = cv::imread("sample_img.jpg");
    std::cout<<"No. of rows: "<<img.rows<<"\nNo. of colums: "<<img.cols<<std::endl;
    int rows = img.rows;
    int col = 200;
    int width = 10;
    int width_pass = col + width;
    for(int j = col;j<width_pass;j++){

        for(int i = 0;i<rows;i++){
            img.at<cv::Vec3b>(i,j)[0]= 255;
            img.at<cv::Vec3b>(i,j)[1]= 255;
            img.at<cv::Vec3b>(i,j)[2]= 255;
        }
    }

    std::cout<<"\n\nThe value of channel 0 of pixel at (100,200) is "<<img.at<cv::Vec3b>(100,200)<<"\n\nTask accomplished"<<std::endl;
    cv::imshow("output window",img);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

//Note:
/*
    For accessing a pixel value from an image follow this flow:

    First initialize Mat image structure:

    cv::Mat img = cv::imread("sample_img.jpg");

    Then acces the element using img.at<data_type/return_type>(row,col)[Channel no.0,1,2];

    For assigning value to a pixel use:
    img.at<cv::Vec3b>(100,200)[0] = 255;
    Here value 255 is assigned to the channel 0 of the 3 channel pixel placed at (100 row, 200 col);

    For accessing/reading value from a pixel use:
    std::cout<<img.at<cv::Vec3b>(100,200)<<std::endl;

    This line will return a vector of 3 values of the 3 respective channels at pixel(100,200)

-Viraj Padte

*/

