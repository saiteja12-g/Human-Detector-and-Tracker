#ifndef INCLUDE_POSE_ESTIMATER_HPP_
#define INCLUDE_POSE_ESTIMATER_HPP_

#include <string>
#include <vector>
#include <memory>

#include <tracker.hpp>

namespace acme_robotics {
  enum ModelMode {
      /// Complete detection & tracker module
      Validation = 0,
      /// Acquiring data for training
      Training,
      /// Testing detector module with user provided test
      /// data and output metrics
      Testing
  };
/**
 * @brief Acme Robotics - Human Tracker
 * 
 * Mode selection is at user's disposal to select as required
 * Display human's coordinates with respect to Robot reference frame
 * 
 */
class pose_estimater {
 public:

      pose_estimater();
      ~pose_estimater();
     /// Initializing essential funtions based on selected mode of operation
      double FindDepth();
      double DepthToPose();

 private:
  double bounded_pixels_;
  double depth_;
};
}  // namespace acme_robotics

#endif  // INCLUDE_POSE_ESTIMATER_HPP_