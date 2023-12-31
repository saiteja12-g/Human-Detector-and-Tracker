/**
 * @file test.cpp
 * @author Akashkumar Parmar (Driver) (akasparm@umd.edu)
 * @author Sai Teja Gilukara (Navigator) (saitejag@umd.edu)
 * @brief Test cases declarations - test cases for sample images
 * @version 0.1
 * @date 2023-10-31
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <gtest/gtest.h>

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

// #include "./../app/post_process.cpp"
#include "./../include/bbox.hpp"
#include "./../include/post_process.hpp"
#include "./../include/pre_process.hpp"

cv::Mat img1 = cv::imread("./../app/resources/sample1.jpg");
cv::Mat img2 = cv::imread("./../app/resources/sample2.jpg");
cv::Mat img3 = cv::imread("./../app/resources/sample3.jpg");
cv::Mat img4 = cv::imread("./../app/resources/sample4.jpg");
cv::Mat img5 = cv::imread("./../app/resources/sample5.jpg");

cv::Mat testImage = img1;

// Create an instance of the Preprocess class
Preprocess preprocessor;

cv::dnn::Net model;

std::vector<cv::Mat> processedFrames =
    preprocessor.pre_process(testImage, model);

// cv::dnn::Net testNet =
// cv::dnn::readNet("./../resources/models/yolov5s.onnx");

/**
 * @brief Test case - 1
 *
 */
TEST(Test1, should_pass) { EXPECT_EQ(1, 1); }

/**
 * @brief Test case - 2
 *
 */
TEST(Test2, testLabel) {
  std::string bounding_box_label = "Person:1";
  int top = 20;
  int left = 20;
  Bbox obj;
  ASSERT_NO_THROW(obj.bbox(img1, bounding_box_label, left, top));
}

/**
 * @brief Test case - 3
 *
 */
TEST(Test3, testLabel) {
  std::string bounding_box_label = "Person:1";
  int top = 20;
  int left = 20;
  Bbox obj;
  ASSERT_NO_THROW(obj.bbox(img2, bounding_box_label, left, top));
}

/**
 * @brief Test case - 4
 *
 */
TEST(Test4, testLabel) {
  std::string bounding_box_label = "Person:1";
  int top = 20;
  int left = 20;
  Bbox obj;
  ASSERT_NO_THROW(obj.bbox(img3, bounding_box_label, left, top));
}

/**
 * @brief Test case - 5
 *
 */
TEST(Test5, testLabel) {
  std::string bounding_box_label = "Person:1";
  int top = 20;
  int left = 20;
  Bbox obj;
  ASSERT_NO_THROW(obj.bbox(img4, bounding_box_label, left, top));
}

/**
 * @brief Test case - 6
 *
 */
TEST(Test6, testLabel) {
  std::string bounding_box_label = "Person:1";
  int top = 20;
  int left = 20;
  Bbox obj;
  ASSERT_NO_THROW(obj.bbox(img5, bounding_box_label, left, top));
}
