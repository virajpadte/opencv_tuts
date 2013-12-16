#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>

int main(){
   cv::Mat img,img2,imgcpy;
   img = cv::imread("lena.jpg");
   img2 = img;
   img.copyTo(imgcpy);
   cv::imshow("img_prior2flip",img);
   cv::imshow("img2_prior2flip",img2);
   cv::flip(img,img2,0);
   cv::imshow("img",img);
   cv::imshow("img2",img2);
   cv::imshow("imgcpy",imgcpy);
   std::cout<<"\nThe image size: "<<imgcpy.size()<<std::endl;
   std::cout<<"\n\nimgcpy loaded"<<std::endl;
   cv::waitKey(0);
   cv::destroyAllWindows();
}
//Note:
/*
    img and img2 are two pointers pointing to the same image data.
    This is done by declaring img first and then using img2 = img

    img.copy2(destination) is a method used to copy one image data to other.

- Viraj Padte
*/
