
#ifndef INCLUDE_LABEL_HPP_
#define INCLUDE_LABEL_HPP_

#include <algorithm>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <string>

class Bbox {
 public:
  cv::Scalar BLACK = cv::Scalar(0, 0, 0);
  cv::Scalar YELLOW = cv::Scalar(0, 255, 255);
  const float FONT_SCALE = 0.7;
  const int FONT_FACE = cv::FONT_HERSHEY_COMPLEX;
  const int THICKNESS = 1;

  void bbox(const cv::Mat &input_frame, std::string bounding_box_label,
            int left, int top) {
    int bottomLine;
    cv::Size boxSize = cv::getTextSize(bounding_box_label, FONT_FACE,
                                       FONT_SCALE, THICKNESS, &bottomLine);
    top = cv::max(top, boxSize.height);

    cv::Point topLeftCorner = cv::Point(left, top);

    cv::Point bottomRIghtCorner =
        cv::Point(left + boxSize.width, top + boxSize.height + bottomLine);

    cv::rectangle(input_frame, topLeftCorner, bottomRIghtCorner, BLACK,
                  cv::FILLED);

    cv::putText(input_frame, bounding_box_label,
                cv::Point(left, top + boxSize.height), FONT_FACE, FONT_SCALE,
                YELLOW, THICKNESS);
  }
};

#endif  // INCLUDE_LABEL_HPP_
