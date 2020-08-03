## transform_by_data(vector<cv::Point2f> pts, Json::array homography_data)

### args

- pts : std::vector<cv::Point2f>
  - 変換したい画像内の点の座標を与える


- homography_data : json11::Json::array
  - ローカル座標とグローバル座標のマッピング

```json
[
  {
    "src": [1387, 756],
    "dist": [1132, 204]
  },
  ...
]
```


### return

変換後の２次元座標(`std::vector<double>`)を返す。


### Example

```cpp
json11::Json::array homography_data = read_json_obj("sample.json");
std::vector<cv::Point2f> pts({cv::Point2f(100,100),});
cv::Mat result = transform_by_data(pts,homography_data);
std::cout << result << std::endl;
```

## transform_by_camparam(std::vector<cv::Point2f> pts, cv::Mat K, cv::Mat D, cv::Mat P)

### args

- pts : vector<cv::Point2f>
  - 変換対象の２次元座標

- K : cv::Mat 3x3
  - 内部パラメーター

- D : cv::Mat 1x5
  - 歪み係数

- P : cv::Mat 3x4
  - 外部パラメーター

### return
変換後の２次元座標(`std::vector<double>`)を返す。

### Example

```cpp
std::vector<cv::Point2f> pts({cv::Point2f(486,342),});

cv::Mat K = (cv::Mat_<double>(3, 3) << 734.69459519, 0, 484.51819542, 0, 733.98229803, 249.00882533, 0, 0, 1);
cv::Mat D = (cv::Mat_<double>(1, 5) << 0.06717359, -0.05946432, -0.00226853, 0.00100395, -0.17334176);
cv::Mat P = (cv::Mat_<double>(3, 4) << 779.441115, 358.391591, -196.369593, 6342.90297, -8.08916461, -68.7457744, -771.974088, 14644.9530, 0.101815604, 0.908825753, -0.404560668, 29.3131634);

std::vector<double> result = transform_by_camparam(pts, K, D, P);
std::cout << result << std::endl;
```
