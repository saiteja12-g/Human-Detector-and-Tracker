/**
 * @file pose_estimater.cpp
 * @brief Implementation of the pose_estimater class
 *
 * This file contains the implementation of the `acme_robotics::pose_estimater`
 * class. The class provides functionality related to depth estimation and pose
 * calculations.
 *
 * @author Sai Teja Gilukara (Driver) (saitejag@umd.edu)
 * @author Akashkumar Parmar (Navigator) (akasparm@umd.edu)
 * @version 0.1
 * @date 2023-10-23
 *
 * @copyright Copyright (c) 2023
 */

#include <../include/pose_estimater.hpp>
#include <optional>
#include <algorithm>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>

namespace acme_robotics {

// Constructor for the pose_estimater class
pose_estimater::pose_estimater() : bounded_pixels_(0.0), depth_(0.0) {}

// Destructor for the pose_estimater class
pose_estimater::~pose_estimater() {}

// Implementation of the FindDepth function
/**
 * @brief Estimate depth based on a bounding box and calibration factor.
 *
 * This function estimates the depth based on a bounding box and a calibration
 * factor. It is a placeholder implementation for testing.
 *
 * @return The estimated depth value.
 */
double pose_estimater::FindDepth() {
  // Placeholder values for testing
  cv::Rect boundingBox(10, 20, 30,
                       40);  // Placeholder bounding box (x, y, width, height)
  double calib_factor = 0.123;  // Placeholder calibration factor

  acme_robotics::Utils::PixelsToDepth(boundingBox, calib_factor);

  return false;
}

// Implementation of the DepthToPose function
/**
 * @brief Convert depth information to pose information.
 *
 * This function converts depth information to pose information.
 *
 * @return The calculated pose value.
 */
double pose_estimater::DepthToPose() { return 5; }

}  // namespace acme_robotics
