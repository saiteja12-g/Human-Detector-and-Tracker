/**
 * @file bbox.hpp
 * @author Akashkumar Parmar (akasparm@umd.edu)
 * @author Sai Teja Gilukara (saitejag@umd.edu)
 * @brief Class declaration for bbox - making bounding box around the object
 * @version 0.1
 * @date 2023-10-31
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef INCLUDE_BBOX_HPP_
#define INCLUDE_BBOX_HPP_

#include <algorithm>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <string>

/**
 * @brief Bound box design with layout, fond formatting and positioning
 *
 */
class Bbox {
 public:
  cv::Scalar BLACK = cv::Scalar(0, 0, 0);
  cv::Scalar YELLOW = cv::Scalar(0, 255, 255);
  const float SCALE = 0.7;
  const int STYLE = cv::FONT_HERSHEY_COMPLEX;
  const int THICKNESS = 1;

  /**
   * @brief Assigns label with class ID, draws a bounding box around the
   * detected object
   *
   * @param instantaneous_frame Instantaneous Vidoe frame retrieved from the
   * camera
   * @param bounding_box_label Label content as input
   * @param leftPoint Left-most column of bounding box drawn over detection
   * @param topPoint Top-most row of bouding box drawn over detection
   */
  void bbox(const cv::Mat &instantaneous_frame, std::string bounding_box_label,
            int leftPoint, int topPoint) {
    int bottomLine;
    cv::Size bSize = cv::getTextSize(bounding_box_label, STYLE, SCALE,
                                     THICKNESS, &bottomLine);
    topPoint = cv::max(topPoint, bSize.height);

    cv::Point topLeftcorner = cv::Point(leftPoint, topPoint);

    cv::Point bottomRIghtCorner = cv::Point(
        leftPoint + bSize.width, topPoint + bSize.height + bottomLine);

    // Draw a filled rectangle as the background for the label
    cv::rectangle(instantaneous_frame, topLeftcorner, bottomRIghtCorner, BLACK,
                  cv::FILLED);

    // Put the text label on the frame
    cv::putText(instantaneous_frame, bounding_box_label,
                cv::Point(leftPoint, topPoint + bSize.height), STYLE, SCALE,
                YELLOW, THICKNESS);
  }
};

#endif  // INCLUDE_BBOX_HPP_
