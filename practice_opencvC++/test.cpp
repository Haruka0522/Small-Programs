#include <opencv2/opencv.hpp>
int main() {
    cv::Mat img = cv::imread("sample.jpg", -1);
    if(img.empty()) {
        return -1;
    }
    cv::namedWindow("ex", cv::WINDOW_AUTOSIZE);
    cv::imshow("ex", img);
    cv::waitKey(0);
    cv::destroyWindow("ex");
    return 0;
}
