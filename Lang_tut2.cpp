#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>

int main(){
    cv::Mat img = cv::imread("lena.jpg");
    cv::Mat res_img;

    if (!img.data){
        std::cout<<"\n\nImage not found"<<std::endl;
        cv::waitKey(0);
        cv::destroyAllWindows();
        return 0;
    }
    cv::namedWindow("Original Image");
    cv::namedWindow("Processed Image");
    cv::flip(img,res_img,-1);
    cv::imshow("Original Image",img);
    cv::imshow("Processed Image",res_img);
    cv::imwrite("Processed Image.jpg",res_img);
    //Validate that the image is stored;

    cv::Mat check_img = cv::imread("Processed Image.jpg");
    if(!check_img.data){
        std::cout<<"\n\nProblem is storing image please check the code"<<std::endl;
    }
    else{
        std::cout<<"\n\nImage stored. Program execution done. The image size is "<<img.size()<<" pixels."<<std::endl;
        cv::waitKey(0);
        cv::destroyAllWindows();
        return 0;
    }
}
//Note:
/*
    Using res_img for storing the result image

    cv::flip(src,dest,flip_mode) is used for flipping the image.

    v::imwrite is used for storing an image.

- Viraj Padte
*/
