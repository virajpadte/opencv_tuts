#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>


//Delaring namespaces
using namespace cv;
using namespace std;

//Main function:

int main(){
    Mat img = imread("sample_img.jpg");
    cout<<"Padding flag: "<<img.isContinuous()<<endl;
    if(img.isContinuous()){
        cout<<"\n\nThe image is padded"<<endl;
    }
    else{
        cout<<"\n\nThe image is not padded"<<endl;
    }
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

