#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>

int main(){
    // The usual method of declaring images:
    cv::Mat img = cv::imread("sample_img.jpg");

    //validate image data:
    if(!img.data){
        std::cout<<"\n\nSome problem with image data please make sure that you check for a valid image in the program directory"<<std::endl;
    }

    //Alternative method of image declaration:
    cv::Mat_<cv::Vec3b> image = img.clone();

    cv::imshow("output",img);
    cv::Vec3b pixel_val = img.at<cv::Vec3b>(100,150);
    std::cout<<"\n\n\nPixel value at (100,150) is "<<pixel_val<<"\n\n\nPixel value at (100,150) using alternative declaration is "<<image(100,150)<<"\n\n\nTask accomplished"<<std::endl;
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

//Note:
/*

 Some more code on alternative declaration for images.

- Viraj Padte

*/

