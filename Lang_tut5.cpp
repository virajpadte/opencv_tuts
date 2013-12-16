#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>


int main(){
    //Declaring an image structure based on IPL C-based
    IplImage *image = cvLoadImage("lena.jpg");
    cv::Ptr<IplImage> image_xtracpy = cvLoadImage("lena.jpg");

    //Interfacing c and c++ based declaration
    cv::Mat img(image,false);

    //Processing the image
    cv::Mat img2 = img.clone();
    cv::flip(img2,img,1);

    //display C based image
    cvNamedWindow("c interface window",CV_WINDOW_AUTOSIZE);
    cvShowImage("c interface window",image);
    cvShowImage("c interface with encapsulated Ptr",image);

    //Dipaly C++ image
    cv::imshow("c++ img",img);
    cv::waitKey(0);

    //relese the c structure that is used to save the image
    cvReleaseImage(&image);

    //Destroy all windows
    cv::destroyAllWindows();

    //Program exesution validation
    std::cout<<"Program execution done"<<std::endl;
}
//Note:
/*
    This tutorial is based on juggling between c and c++ based interfaces for using Intel's OPENCV library.

    cv::Mat img(image,false);

    Imp snippet for combining c and c++ based codes

    cv::Mat img(c-pointer ,true/false );

    false: Point to the same memory assigned to the image

    true: Create a new copy of the same and assigns it to the c++ based Mat structure.

    Alternative method of doing this is to use the following :
    cv::Ptr<IplImage> image_xtracpy  = cvLoadImage("lena.jpg");

    Encapsulating IplImage with Ptr will save the efforts of releasing memory allocated to the structure.

    Hence cvReleaseImage(&image_xtracpy ) is not required.


- Viraj Padte

*/
