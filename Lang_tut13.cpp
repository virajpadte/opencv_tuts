#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>

//Delaring namespaces
using namespace cv;
using namespace std;


//Declaring functions:
Mat colour_reduce(Mat img,int factor,int flag);
void colorReduce(cv::Mat &image, int div=64);


//defining functions:
Mat colour_reduce(Mat img,int factor,int flag){
    int rows = img.rows;
    int cols = img.cols*img.channels();
    switch (flag){

    case 1:
        //Case for handling continuous images
        cols = rows*cols;
        rows = 1;
        for(int i = 0; i< rows;i++){
            uchar * img_pointer = img.ptr<uchar>(i);
            for(int j = 0; j< cols;j++){
                img_pointer[j] =img_pointer[j]/factor*factor + factor/2;
            }
        }
        break;

    case 2:
        //Case for handling padded images
        for(int i = 0;i< rows;i++){
            uchar * img_pointer = img.ptr<uchar>(i);
            for(int j = 0; j< cols;j++){
                img_pointer[j] =img_pointer[j]/factor*factor + factor/2;
            }
        }
        break;
    }
    return img;
}

//Main function:

int main(){
    Mat img = imread("sample_img.jpg");
    imshow("Original image",img);
    int case_flag;
    if(img.isContinuous()){
        cout<<"The image is continuous i.e unpadded."<<endl;
        case_flag = 1;
    }
    else{
        cout<<"The image is padded"<<endl;
        case_flag = 2;
    }

    Mat pr_img = colour_reduce(img,64,case_flag);
    imshow("Processed Image",pr_img);
    waitKey(0);
    destroyAllWindows();
    return 0;
}



//Note:
/*

Pre-requisites:

Understanding Padding in images: Please go through ref links folder.

Exploiting padding in images for scanning.
When a image is not padded, It can ne seen as a long one dimensional array.We can take advantage of this property while scanning such an image.

- Viraj Padte
*/

