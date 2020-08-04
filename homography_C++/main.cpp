#include "json11.hpp" 
#include "homography.hpp"
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>


int main()
{
    { //transform_by_data()のテスト
        json11::Json::array homography_data = read_json_obj("sample.json");

        //変換する座標
        std::vector<cv::Point2f> pts({
            cv::Point2f(100, 100),
        });

        std::vector<double> result = transform_by_data(pts, homography_data);
        std::cout << result << std::endl;
    }

    { //transform_by_camparam()のテスト
        //変換する座標
        std::vector<cv::Point2f> pts({
            cv::Point2f(486, 342),
        });

        cv::Mat K = (cv::Mat_<double>(3, 3) << 734.69459519, 0, 484.51819542, 0, 733.98229803, 249.00882533, 0, 0, 1);
        cv::Mat D = (cv::Mat_<double>(1, 5) << 0.06717359, -0.05946432, -0.00226853, 0.00100395, -0.17334176);
        cv::Mat P = (cv::Mat_<double>(3, 4) << 779.441115, 358.391591, -196.369593, 6342.90297, -8.08916461, -68.7457744, -771.974088, 14644.9530, 0.101815604, 0.908825753, -0.404560668, 29.3131634);

        std::vector<double> result = transform_by_camparam(pts, K, D, P);
        std::cout << result << std::endl;
    }
}
