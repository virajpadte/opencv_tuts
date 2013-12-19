#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>

cv::Mat open_image(){
    IplImage *imgc = cvLoadImage("lena.jpg");
    cv::Mat img(imgc,false);
    //Validate the opening process:
    if(!img.data){
        std::cout<<"\n\n\nThere is some error pls check your code"<<std::endl;
    }


    return img;
}

cv::Mat process_image(cv::Mat image){
    cv::Mat buf_img = image.clone();
    cv::flip(image,buf_img,0);
    return buf_img;
}
int main(){
    // Call function to open image
    cv::Mat image = open_image();
    cv::imshow("Before parsing through process function",image);
    image = process_image(image);
    cv::imshow("processd image",image);
    cv::waitKey(0);
    std::cout<<"\n\n\nwork done........"<<std::endl;
    cv::destroyAllWindows();
}
//Note:
/*
    Playing with functions a mix of c and c++ functions.


-Viraj Padte

*/
