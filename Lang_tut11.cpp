#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>

using namespace cv;
using namespace std;


void understanding_pointers(){
    int a  = 10;
    int *point2addr = &a;
    //Instruction interface
    cout<<"            Understanding Pointers\n\n First we make an attempt to understand pointers.\n Then we will use pointer logic for accessing images."<<endl;
    cout<<"\n\n Please refer to the understanding_pointers() function"<<endl;
    //fucntion output
    cout<<"\n\n Value of a "<<a<<"\n\n Address of a "<<*point2addr<<endl;
}


Mat color_reduction(Mat i,int factor){
    for(int l=0;l<i.rows;l++){
        uchar *data = i.ptr<uchar>(l);
        for(int m = 0;m<(i.channels()*i.cols);m++){
            data[m] = data[m]/factor * factor + 32;
        }
    }
    return i;
}

Mat alter_color_reduction(Mat_<Vec3b> image1,int factor){
    for(int i=0;i<image1.rows;i++){
        for(int j = 0;j<image1.cols;j++){
            image1(i,j)[0] = image1(i,j)[0]/factor*factor +32;
            image1(i,j)[1] = image1(i,j)[1]/factor*factor +32;
            image1(i,j)[2] = image1(i,j)[2]/factor*factor +32;
        }
    }
    return image1;
}


int main(){
    Mat image = imread("sample_img.jpg");
    imshow("Original image",image);
    understanding_pointers();
    imshow("Processed image",color_reduction(image,64));
    imshow("Alternative processed image",alter_color_reduction(image,64));
    waitKey(0);
    destroyAllWindows();
    return 0;
}


//Note:
/*
Here we wil learn to access an image using pointers.For this we first revise pointer logic.

Lets take an small code snippet:
    int a = 10;  - This assigns a value 10 to the variable a which holds value 10 in a memory location.

    int *pointer2a = &a;

Here we have created a pointer named pointer2a and we have assigned it a value which is the address of a(&a - this notation is used for indicating address)

Now applying the same logic to opencv, the library gives a method for Mat structure called ptr.
This is used as follows:

cv::Mat_<cv::Vec3b> image  = imread("sample_img.jpg");
uchar *pointer2rowaddress = image.ptr<uchar>(col no.)

Now for accessing the data pointed we use:

m = col*no.of channels
pointer2rowaddress[m] =pointer2rowaddress[m]/64;

Alternatively we can also use:

for(int  i =0; i<image.rows;i++){
    for(int j = 0;j<image.cols;j++){
        image(i,j)[0] = image(i,j)[0]/factor*factor +32;
        image(i,j)[1] = image(i,j)[1]/factor*factor +32;
        image(i,j)[2] = image(i,j)[2]/factor*factor +32;
}



- Viraj Padte

*/


