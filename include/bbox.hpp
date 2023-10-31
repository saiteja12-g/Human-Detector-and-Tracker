
#ifndef INCLUDE_BBOX_HPP_
#define INCLUDE_BBOX_HPP_

#include <algorithm>
#include <string>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>


class Bbox {
 public:
  cv::Scalar BLACK = cv::Scalar(0, 0, 0);
  cv::Scalar YELLOW = cv::Scalar(0, 255, 255);
  const float SCALE = 0.7;
  const int STYLE = cv::FONT_HERSHEY_COMPLEX;
  const int THICKNESS = 1;

  void bbox(const cv::Mat &input_frame, std::string bounding_box_label,
            int leftPoint, int topPoint) {
    int bottomLine;
    cv::Size bSize = cv::getTextSize(bounding_box_label, STYLE,
                                       SCALE, THICKNESS, &bottomLine);
    topPoint = cv::max(topPoint, bSize.height);

    cv::Point topLeftcorner = cv::Point(leftPoint, topPoint);

    cv::Point bottomRIghtCorner =
        cv::Point(leftPoint + bSize.width, topPoint + bSize.height + bottomLine);

    cv::rectangle(input_frame, topLeftcorner, bottomRIghtCorner, BLACK,
                  cv::FILLED);

    cv::putText(input_frame, bounding_box_label,
                cv::Point(leftPoint, topPoint + bSize.height), STYLE, SCALE,
                YELLOW, THICKNESS);
  }
};

#endif  // INCLUDE_BBOX_HPP_
