#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>

cv::Mat salt_n_pepper(cv::Mat_<cv::Vec3b> bufimage){
    //cv::Mat_<cv::Vec3b> bufimage  = image;

    int counter = 500;
    for(int a = 0;a<counter;a++){
        //Random pixel accessing logic
        int i = rand()%bufimage.rows;
        int j = rand()%bufimage.cols;

        if(bufimage.channels()==1){
            bufimage(i,j)=255;
        }
        else if(bufimage.channels()==3){

            bufimage(i,j)[0]=255;
            bufimage(i,j)[1]=255;
            bufimage(i,j)[2]=255;

            }
    }
    return bufimage;
}
int main(){
    //This is a new way of declaring the image:

    cv::Mat_<cv::Vec3b> img = cv::imread("sample_img.jpg");
    cv::Mat Processed_img = salt_n_pepper(img);
    cv::imshow("output",Processed_img);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

//Note:
/*

This code gives an alternative for img.at for accessing pixels.

For this first declare the image in the following manner:
    cv::Mat img = cv::imread("sample_img.jpg");
    cv::Mat_<cv::Vec3b> image = img;

- Viraj Padte

*/

