#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>

//Delaring namespaces
using namespace cv;
using namespace std;


//Declaring functions:
Mat colour_reduce(Mat img,int factor);

//defining functions:

Mat colour_reduce(Mat img,int factor){
    int case_flag = 0;
    if(img.isContinuous()){
        case_flag = 1;
    }
    else{
        case_flag = 2;
    }

    switch(case_flag){
        case 1:{
            cout<<"Continuous flag set"<<endl;
            break;
        }
        case 2:{
            cout<<"Continuous flag reset"<<endl;
            break;
        }
    }
    return img;
}

//Main function:

int main(){
    Mat img = imread("sample_img.jpg");
    cout<<"Padding flag: "<<img.isContinuous()<<endl;
    if(img.isContinuous()){
        cout<<"\n\nThe image is not padded"<<endl;
    }
    else{
        cout<<"\n\nThe image is padded"<<endl;
    }
    colour_reduce(img,64);
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

