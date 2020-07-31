#include <cassert>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <fstream>
#include "json11.hpp"
#include <list>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <type_traits>

//vectorもcoutできるようにするやつ
template <class T>std::ostream &operator<<(std::ostream &o,const std::vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}


cv::Mat _get_homography_matrix(json11::Json::array homography_data)
{
    int data_size = homography_data.size();
    std::vector<cv::Point2f> src_tmp(data_size);
    std::vector<cv::Point2f> dist_tmp(data_size);

    for (int i=0;i<data_size;i++)
    {
        src_tmp.at(i) = cv::Point2f(homography_data.at(i)["src"].array_items().at(0).int_value(),homography_data.at(i)["src"].array_items().at(1).int_value());
        dist_tmp.at(i) = cv::Point2f(homography_data.at(i)["dist"].array_items().at(0).int_value(),homography_data.at(i)["dist"].array_items().at(1).int_value());
    }

    /*
    cv::Mat src_mat(src_tmp);
    cv::Mat dist_mat(dist_tmp);
    cv::Mat src = src_mat.reshape(2,data_size);
    cv::Mat dist = dist_mat.reshape(2,data_size);
    */
    std::cout << cv::format(src_tmp,cv::Formatter::FMT_PYTHON) << std::endl;
    std::cout << cv::format(dist_tmp,cv::Formatter::FMT_PYTHON) << std::endl;
    const cv::Mat H = cv::findHomography(src_tmp,dist_tmp,cv::RANSAC);

    return H;
}


/*
int transform_by_camparam(const cv::Mat pts,
                              const cv::Mat K,
                              const cv::Mat D,
                              const cv::Mat P)
{
    cv::Mat P_z0, P_z0_inv, dst, ixyz, wxyz;
    P_z0 = P.resize(2);
    P_z0_inv = P_z0.inv();
    cv::undistortPoints(pts, dst, K, D, cv::noArray(), K);
    std::cout << dst << std::endl;

    return 1;
}
*/

cv::Mat transform_by_data(std::vector<cv::Point2f> pts, json11::Json::array homography_data)
{
    cv::Mat ret;
    cv::Mat H = _get_homography_matrix(homography_data);
    std::cout << H << std::endl;
    cv::perspectiveTransform(pts, ret, H);

    return ret;
}


inline std::string read_txt(std::string const& path)
{
    std::ifstream ifs(path);
    std::stringstream buffer;
    buffer << ifs.rdbuf();
    std::string str = buffer.str();
    // UTF-8のBOM付きをチェック
    if (str.size() >= 3 && str[0] == -17 && str[1] == -69 && str[2] == -65)  return str.substr(3);
    else  return str;
}

json11::Json::array read_json_obj(std::string path)
{
    std::ifstream ifs(path);
    if (!ifs)
    {
        throw std::runtime_error("File cannnot be opened");
    }

    std::string str_file = read_txt(path);
    std::string err;
    auto json = json11::Json::parse(str_file, err);
    //std::cout << str_file << std::endl;
    return json.array_items();
}

int main()
{
    json11::Json::array homography_data = read_json_obj("sample.json");
    //cv::Mat pts = (cv::Mat_<double>(1, 1) << 234, 222);
    std::vector<cv::Point2f> pts(1);
    pts.at(0) = cv::Point2f(200,200);
    //pts.push_back(cv::Point2f(200,200));
    cv::Mat result = transform_by_data(pts, homography_data);
    std::cout << result << std::endl;
}
