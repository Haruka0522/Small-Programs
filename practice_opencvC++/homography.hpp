#include <vector>
#include <sstream>
#include <fstream>
#include "json11.hpp"
#include <opencv2/opencv.hpp>

//vectorもcoutできるようにするやつ
template <class T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v)
{
    o << "{";
    for (int i = 0; i < (int)v.size(); i++)
        o << (i > 0 ? ", " : "") << v[i];
    o << "}";
    return o;
}
json11::Json::array read_json_obj(std::string path);
std::vector<double> transform_by_data(std::vector<cv::Point2f> pts, json11::Json::array homography_data);
std::vector<double> transform_by_camparam(const std::vector<cv::Point2f> pts, const cv::Mat K, const cv::Mat D, const cv::Mat P);