/**
 * @file test.cpp
 * @brief Unit tests for various functionalities
 *
 * This file contains unit tests for the functionality of the `acme_robotics`
 * classes. Each test case checks the expected output or behavior of a specific
 * function.
 *
 * @author Akashkumar Parmar (Driver) (akasparm@umd.edu)
 * @author Sai Teja Gilukara (Navigator) (saitejag@umd.edu)
 * @version 0.1
 * @date 2023-10-24
 *
 * @copyright Copyright (c) 2023
 */

#include <gtest/gtest.h>
#include <type_traits>

#include <../include/detector.hpp>
#include <../include/pose_estimater.hpp>
#include <../include/tracker.hpp>

// Test for the DetectObject function in the Detector class
TEST(Object_detection_test, Output_must_be_a_boolean_value) {
  acme_robotics::Detector Detector;
  bool output = Detector.DetectObject();
  ASSERT_EQ(output, false);
}

// Test for the GetCurrentPose function in the Tracker class
TEST(Get_position_test, Output_must_be_a_double_value) {
  acme_robotics::Tracker Tracker;
  bool output = Tracker.GetCurrentPose();
  ASSERT_TRUE((std::is_same<decltype(output), double>::value));
}

// Test for the GetNextPose function in the Tracker class
TEST(Get_Next_pose, Output_must_be_a_double_value) {
  acme_robotics::Tracker Tracker;
  bool output = Tracker.GetNextPose();
  ASSERT_TRUE((std::is_same<decltype(output), double>::value));
}

// Test for the FindDepth function in the pose_estimater class
TEST(Find_Depth_test_1, Output_must_be_a_double_value) {
  acme_robotics::pose_estimater pose_estimater;
  bool output = pose_estimater.FindDepth();
  ASSERT_TRUE((std::is_same<decltype(output), double>::value));
}

// Test for the FindDepth function in the pose_estimater class, checking for a
// positive value
TEST(Find_Depth_test_2, Output_must_be_a_positive_value) {
  acme_robotics::pose_estimater pose_estimater;
  bool output = pose_estimater.FindDepth();
  ASSERT_GT(output, 0);
}

// Test for the DepthToPose function in the pose_estimater class
TEST(Depth_to_pose, Output_must_be_a_double_value) {
  acme_robotics::pose_estimater pose_estimater;
  bool output = pose_estimater.DepthToPose();
  ASSERT_TRUE((std::is_same<decltype(output), double>::value));
}
