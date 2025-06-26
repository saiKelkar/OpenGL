#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Creates a VideoCapture object, cap(0) tries to open the default webcam
    cv::VideoCapture cap(0); // 0 - default webcam
    if(!cap.isOpened()) {
        std::cerr << "Webcam not found!\n";
        return -1;
    }
    // cv::Mat object -- holds each frame (image) captured from the webcam
    cv::Mat frame;
    while(true) {
        // captures a frame from the webcam and stores it in frame
        cap >> frame;
        if(frame.empty()) break;

        // display the frame in a window titled "Webcam Feed"
        cv::imshow("Webcam Feed", frame);
        if(cv::waitKey(1) == 27) break;
    }
    return 0;
}