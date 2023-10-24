
#ifndef INCLUDE_DETECTOR_HPP_
#define INCLUDE_DETECTOR_HPP_

#include <memory>
#include <opencv2/dnn/dnn.hpp>
#include <opencv2/dnn/shape_utils.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <utils.hpp>
#include <vector>

namespace acme_robotics {

class Detector {
 public:
  Detector();
  ~Detector();
  void FilterData();
  double DetectObject();

 private:
  double object_height_;
  double object_width_;
  double input_height_;
  double input_width_;
};
}  // namespace acme_robotics
#endif  // INCLUDE_DETECTOR_HPP_