#ifndef INCLUDE_UTILS_HPP_
#define INCLUDE_UTILS_HPP_

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

#include "opencv2/core/mat.hpp"

namespace acme_robotics {

struct Pose {
  Pose() {
    x = -1.0;
    y = -1.0;
    z = -1.0;
  }

  Pose(double x1, double y1, double z1) {
    x = x1;
    y = y1;
    z = z1;
  }
  double x;
  double y;
  double z;
};

class Utils {
 public:
  static cv::Mat GetBB(cv::Mat i, const cv::Rect &b, const std::string &l);
  static cv::Point TrackNextPoint(const cv::Rect &bbox);
  static Pose PixelsToDepth(const cv::Rect &b, double calib_factor);
};
}  // namespace acme_robotics

#endif  // INCLUDE_UTILS_HPP_