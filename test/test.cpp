#include <gtest/gtest.h>

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

#include "./../include/bbox.hpp"
// #include "./../include/post_process.hpp"
// #include "./../include/pre_process.hpp"

cv::Mat img1 = cv::imread("./../resources/sample1.jpg");
cv::Mat img2 = cv::imread("./../resources/sample2.jpg");
cv::Mat img3 = cv::imread("./../resources/sample3.jpg");
cv::Mat img4 = cv::imread("./../resources/sample4.jpg");
cv::Mat img5 = cv::imread("./../resources/sample5.jpg");
cv::dnn::Net net = cv::dnn::readNet("./../app/resources/models/yolov5s.onnx");

TEST(Test1, should_pass) { EXPECT_EQ(1, 1); }

TEST(Test2, testLabel) {
  std::string bounding_box_label = "Person:1";
  int top = 20;
  int left = 20;
  Bbox obj;
  ASSERT_NO_THROW(obj.bbox(img1, bounding_box_label, left, top));
}

TEST(Test3, testLabel) {
  std::string bounding_box_label = "Person:1";
  int top = 20;
  int left = 20;
  Bbox obj;
  ASSERT_NO_THROW(obj.bbox(img2, bounding_box_label, left, top));
}

TEST(Test4, testLabel) {
  std::string bounding_box_label = "Person:1";
  int top = 20;
  int left = 20;
  Bbox obj;
  ASSERT_NO_THROW(obj.bbox(img3, bounding_box_label, left, top));
}

TEST(Test5, testLabel) {
  std::string bounding_box_label = "Person:1";
  int top = 20;
  int left = 20;
  Bbox obj;
  ASSERT_NO_THROW(obj.bbox(img4, bounding_box_label, left, top));
}

TEST(Test6, testLabel) {
  std::string bounding_box_label = "Person:1";
  int top = 20;
  int left = 20;
  Bbox obj;
  ASSERT_NO_THROW(obj.bbox(img5, bounding_box_label, left, top));
}
