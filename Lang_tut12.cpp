#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>


//Delaring namespaces
using namespace cv;
using namespace std;

//Declaring functions:
Mat inplace_color_reduction(Mat img, int factor);
Mat advanced_color_reduction(const Mat img, int factor);
Mat pointer_based_processing(Mat img,Mat result, int factor);


//defining functions;
Mat inplace_color_reduction(Mat img, int factor){
    for(int i = 0;i<img.rows;i++){
        uchar *img_pointer = img.ptr<uchar>(i);
        for(int j = 0;j<(img.cols*img.channels());j++){
            img_pointer[j] =img_pointer[j]/factor*factor+factor/2;
        }
    }
    return img;
}

Mat advanced_color_reduction(const Mat img, Mat result_img, int factor){
    result_img = img.clone();
    for(int i = 0;i<result_img.rows;i++){
        uchar *img_pointer = result_img.ptr<uchar>(i);
        for(int j = 0;j<(result_img.cols*result_img.channels());j++){
            img_pointer[j] =img_pointer[j]/factor*factor+factor/2;
        }
    }
    return result_img;
}


Mat pointer_based_processing(Mat img,Mat result, int factor){
    result = img.clone();
    for(int i = 0; i<img.rows;i++){
        uchar *source_pointer = img.ptr<uchar>(i);
        uchar *result_pointer = result.ptr<uchar>(i);
        for(int j = 0;j<(img.cols*img.channels());j++){
            result_pointer[j]= source_pointer[j]/factor*factor + factor/2;
        }
    }
    return result;
}

//Defining main function
int main(){
    Mat og_img = imread("sample_img.jpg");
    imshow("Input",og_img);
    Mat buf_img = og_img.clone();
    Mat cr_img = inplace_color_reduction(buf_img,64);
    imshow("CR_output",cr_img);

    //Understanding advanced function
    //This snippet is used fgr understanding advanced_processing:
    Mat new_img;
    Mat output_img_advanced = advanced_color_reduction(buf_img, new_img,64);
    imshow("Advance CR_output - 1",output_img_advanced);

    //This snippet is used fgr understanding inplace_processing:
    Mat output_img_advanced2 = advanced_color_reduction(buf_img, buf_img,64);
    imshow("Advance CR_output - 2",output_img_advanced2);

    //Advanced pointer based pixel processing:
    Mat pointer_img_output;
    Mat pointer_based_output = pointer_based_processing(buf_img,pointer_img_output,64);
    imshow("Advance pointer_based_output",output_img_advanced2);

    waitKey(0);
    destroyAllWindows();
}


//Note:
/*

Use of pointers for pixel processing.

- Viraj Padte
*/

