/**
 * @file utils.cpp
 * @brief Implementation of utility functions
 *
 * This file contains the implementation of utility functions in the
 * `acme_robotics` namespace. These utilities provide various functionalities,
 * such as tracking, image manipulation, and conversion of pixel data to depth
 * information.
 *
 * @author Sai Teja Gilukara (Driver) (saitejag@umd.edu)
 * @author Akashkumar Parmar (Navigator) (akasparm@umd.edu)
 * @version 0.1
 * @date 2023-10-23
 *
 * @copyright Copyright (c) 2023
 */

#include <../include/utils.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>

namespace acme_robotics {

// Implementation of the TrackNextPoint function
/**
 * @brief Track the next point in the bounding box.
 *
 * This function calculates the next point to track within a bounding box.
 *
 * @param bbox The bounding box to track within.
 * @return The calculated point to track.
 */
cv::Point Utils::TrackNextPoint(const cv::Rect &bbox) {
  int x_center = bbox.width / 2 + bbox.x;
  int y_center = bbox.height / 2 + bbox.y;
  return cv::Point(x_center, y_center);
}

// Implementation of the PixelsToDepth function
/**
 * @brief Convert pixel data to depth information.
 *
 * This function converts pixel data from a bounding box to depth information
 * based on a calibration factor.
 *
 * @param b The bounding box containing pixel data.
 * @param calib_factor The calibration factor to use for the conversion.
 * @return The calculated depth information.
 */
acme_robotics::Pose Utils::PixelsToDepth(const cv::Rect &b,
                                         double calib_factor) {
  double height = b.height;
  double calib_distance = calib_factor / height;
  cv::Point centre = acme_robotics::Utils::TrackNextPoint(b);

  return acme_robotics::Pose(calib_distance, centre.x, centre.y);
}

}  // namespace acme_robotics
