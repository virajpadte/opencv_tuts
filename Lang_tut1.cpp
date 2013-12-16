#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>

int main(){
    cv::Mat image = cv::imread("lena.jpg");
    cv::Mat erode = image.clone();
    cv::imshow("window",image);
    cv::imshow("output",erode);
    cv::waitKey(0);
    std::cout<<"\n\n\nimage size: "<<image.size()<<std::endl;
    std::cout<<"program executed properly\n\n\n";
    return 0;
}


//Note:
/*

Use std for c++ commands and cv for opencv commands.Keep switiching the namespace for using the functions


- Viraj Padte
*/
