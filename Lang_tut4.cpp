#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>

cv::Mat function(cv::Mat image) {
// create image
    cv::Mat buf_process;
    cv::flip(image,buf_process,1);
    return buf_process;
}

int main(){
// get a gray-level image
    cv::Mat image = cv::imread("lena.jpg");
    if(!image.data){
        std::cout<<"problem opening the image. Please make sure the required image is in the project directory"<<std::endl;
    }
    cv::imshow("Original image",image);
    cv::Mat gray= function(image);
    cv::imshow("Image returned function",gray);
    cv::waitKey(0);
    std::cout<<"Program execution done"<<std::endl;
    cv::destroyAllWindows();
}
//Note:
/*
    Parsing an image in a function processing and returning image to main function.

- Viraj Padte
*/
