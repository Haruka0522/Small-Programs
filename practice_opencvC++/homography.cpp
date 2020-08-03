#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "json11.hpp"

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

cv::Mat _get_homography_matrix(json11::Json::array homography_data)
{
    int data_size = homography_data.size();
    std::vector<cv::Point2f> src_tmp(data_size);
    std::vector<cv::Point2f> dist_tmp(data_size);

    for (int i = 0; i < data_size; i++)
    {
        src_tmp.at(i) = cv::Point2f(homography_data.at(i)["src"].array_items().at(0).int_value(), homography_data.at(i)["src"].array_items().at(1).int_value());
        dist_tmp.at(i) = cv::Point2f(homography_data.at(i)["dist"].array_items().at(0).int_value(), homography_data.at(i)["dist"].array_items().at(1).int_value());
    }

    cv::Mat src_mat(src_tmp);
    cv::Mat dist_mat(dist_tmp);
    //std::cout << cv::format(src_tmp,cv::Formatter::FMT_PYTHON) << std::endl;
    //std::cout << cv::format(dist_tmp,cv::Formatter::FMT_PYTHON) << std::endl;
    const cv::Mat H = cv::findHomography(src_tmp, dist_tmp, cv::RANSAC);

    return H;
}

std::vector<double> transform_by_camparam(const std::vector<cv::Point2f> pts,
                                          const cv::Mat K,
                                          const cv::Mat D,
                                          const cv::Mat P)
{
    cv::Mat P_z0, P_z0_inv, dst, wxyz_mat;
    std::vector<double> ixyz, wxyz;

    //Pythonの`np.delete(P,[2],axis=1)`の部分
    //もしかしたらもっと綺麗に書く方法があるかも
    for (int i = 0; i < 4; i++)
    {
        if (i == 2)
            continue;
        P_z0.push_back(P.col(i));
    }
    const std::vector<int> shape = {3, 3};
    P_z0 = P_z0.reshape(1, shape);
    P_z0 = P_z0.t();
    P_z0_inv = P_z0.inv();
    cv::undistortPoints(pts, dst, K, D, cv::noArray(), K);

    //型変換が無駄に多いのかも
    //もしかしたらもっと綺麗に書く方法があるかも
    dst = dst.reshape(1, 1);
    dst.copyTo(ixyz);
    ixyz.push_back(1.0);
    cv::Mat ixyz_mat(ixyz, true);
    ixyz_mat = ixyz_mat.reshape(1, 3);
    P_z0_inv = P_z0_inv.reshape(1, 3);
    wxyz_mat = P_z0_inv * ixyz_mat;
    wxyz_mat.copyTo(wxyz);

    std::vector<double> result;
    result.push_back(wxyz.at(0) / wxyz.at(2));
    result.push_back(wxyz.at(1) / wxyz.at(2));

    return result;
}

cv::Mat transform_by_data(std::vector<cv::Point2f> pts, json11::Json::array homography_data)
{
    cv::Mat ret;
    cv::Mat H = _get_homography_matrix(homography_data);
    cv::perspectiveTransform(pts, ret, H);

    return ret;
}

inline std::string read_txt(std::string const &path)
{
    std::ifstream ifs(path);
    std::stringstream buffer;
    buffer << ifs.rdbuf();
    std::string str = buffer.str();
    // UTF-8のBOM付きをチェック
    if (str.size() >= 3 && str[0] == -17 && str[1] == -69 && str[2] == -65)
        return str.substr(3);
    else
        return str;
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
    return json.array_items();
}

int main()
{
    { //transform_by_data()のテスト
        json11::Json::array homography_data = read_json_obj("sample.json");

        //変換する座標
        std::vector<cv::Point2f> pts({cv::Point2f(100,100),});

        cv::Mat result = transform_by_data(pts, homography_data);
        std::cout << result << std::endl;
    }

    { //transform_by_camparam()のテスト
        //変換する座標
        std::vector<cv::Point2f> pts({cv::Point2f(486,342),});

        cv::Mat K = (cv::Mat_<double>(3, 3) << 734.69459519, 0, 484.51819542, 0, 733.98229803, 249.00882533, 0, 0, 1);
        cv::Mat D = (cv::Mat_<double>(1, 5) << 0.06717359, -0.05946432, -0.00226853, 0.00100395, -0.17334176);
        cv::Mat P = (cv::Mat_<double>(3, 4) << 779.441115, 358.391591, -196.369593, 6342.90297, -8.08916461, -68.7457744, -771.974088, 14644.9530, 0.101815604, 0.908825753, -0.404560668, 29.3131634);

        std::vector<double> result = transform_by_camparam(pts, K, D, P);
        std::cout << result << std::endl;
    }
}
