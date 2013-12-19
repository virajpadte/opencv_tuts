#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>

// This is the processing function which is used to add Salt_N_Pepper noise

cv::Mat salt_n_pepper(cv::Mat image, int noise){
    for(int counter =0;counter<noise;counter++){
        int i = rand()%image.rows;
        int j = rand()%image.cols;
        if(image.channels()== 1){
            image.at<uchar>(i,j) = 255;
        }
        else if(image.channels()== 3){
            image.at<cv::Vec3b>(i,j)[0] = 255;
            image.at<cv::Vec3b>(i,j)[1] = 255;
            image.at<cv::Vec3b>(i,j)[2] = 255;
        }
     }
    return image;
}

// This function is just written for understanding the use of rand() fucntion:

int rand_values(){
    int counter = 10;
    for(int i = 0;i<counter;i++){
        int j = rand()%200;
        std::cout<<"\n\nPrint value of j "<<j;
    }
}

int main(){
    cv::Mat img = cv::imread("sample_img.jpg");
    //validate image data:
    if(!img.data){
        std::cout<<"There is some accessing the required image file"<<std::endl;
    }
    else{
        std::cout<<"Image size is "<<img.rows<<" * "<<img.cols<<std::endl;
        rand_values();
        cv::Mat processed_image = salt_n_pepper(img,1000);
        cv::imshow("Processed image",processed_image);
        cv::waitKey(0);
        cv::destroyAllWindows();
        std::cout<<"\n\n\n\nTask accomplished\n\n"<<std::endl;
    }
}

//Note:
/*
While working with random numbers make use of rand( ) in the following way:

int x = rand()%100 - puts a upper limit on the output of the random number function.
By default the lower limit is 0.

- Viraj Padte

*/

