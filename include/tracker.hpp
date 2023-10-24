
#ifndef INCLUDE_TRACKER_HPP_
#define INCLUDE_TRACKER_HPP_

#include <opencv2/core/types.hpp>
#include <memory>
#include <vector>

#include <opencv2/core/ocl.hpp>
#include <opencv2/tracking.hpp>

#include <detector.hpp>

namespace acme_robotics {

class Tracker{
 public:
  Tracker();
  ~Tracker();
  double GetCurrentPose();
  double GetNextPose();

 private:
  double previous_com_;
  double current_com_;
  std::vector<float> list_com;
};
}  // namespace acme_robotics

#endif  // INCLUDE_TRACKER_HPP_