// /**
//  * @file post_process.hpp
//  * @author Akashkumar Parmar (akasparm@umd.edu)
//  * @author Sai Teja Gilukara (saitejag@umd.edu)
//  * @brief Class declaration for Postprocess - post processing of the image
//  frame
//  * @version 0.1
//  * @date 2023-10-31
//  *
//  * @copyright Copyright (c) 2023
//  *
//  */
// #ifndef INCLUDE_POST_PROCESS_HPP_
// #define INCLUDE_POST_PROCESS_HPP_

// #include <iostream>
// #include <opencv2/opencv.hpp>
// #include <ostream>
// #include <string>
// #include <vector>

// #include "./../include/bbox.hpp"
// #include "./../include/pre_process.hpp"

// /**
//  * @brief Postprocess class defines the outline for postprocessing input
//  frame
//  * based on provided detections and providing resulting image to main
//  function.
//  *
//  */
// class Postprocess : public Preprocess, public Bbox {
//  private:
//   const float SCORE = 0.5;
//   const float NMS = 0.45;
//   const float CONFIDENCE = 0.45;
//   cv::Scalar BLUE = cv::Scalar(255, 0, 0);
//   cv::Scalar RED = cv::Scalar(0, 0, 255);

//  public:
//   /**
//    * @brief The retrieved video frame, detection outputs and eteciton class
//    list
//    * are provided as input to this function. Using these inputs it gives the
//    * confidence level and thresholds filters unwated detections.
//    *
//    * @param instantaneous_frame Input for the post-process functions - The
//    * instantaneous frame captured by the camera
//    * @param preprocess_outputs Detections from preprocessing are utilized to
//    * filter unwated detections based on thresholds
//    * @param class_name List of the different classes. In this case the only
//    * class is 'person'
//    * @return cv::Mat
//    */
//   cv::Mat post_process(cv::Mat instantaneous_frame,
//                        std::vector<cv::Mat> preprocess_outputs,
//                        std::vector<std::string> class_name) {
//     std::vector<int> class_ids;
//     std::vector<float> confidence_list;
//     std::vector<cv::Rect> bounding_boxes;

//     if (preprocess_outputs.empty()) {
//       return instantaneous_frame;
//     }

//     float col_factor = instantaneous_frame.cols / INPUT_WIDTH;
//     float row_factor = instantaneous_frame.rows / INPUT_HEIGHT;

//     float *data = reinterpret_cast<float *>(preprocess_outputs[0].data);

//     const int rows = 25200;

//     for (int i = 0; i < rows; ++i) {
//       float instantaneous_confidence = data[4];
//       if (instantaneous_confidence >= CONFIDENCE) {
//         float *classes_scores = data + 5;

//         cv::Mat scores(1, class_name.size(), CV_32FC1, classes_scores);

//         cv::Point class_id;
//         double max_class_score;
//         minMaxLoc(scores, 0, &max_class_score, 0, &class_id);

//         if (max_class_score > SCORE) {
//           confidence_list.push_back(instantaneous_confidence);
//           class_ids.push_back(class_id.x);

//           float cx = data[0];
//           float cy = data[1];

//           float w = data[2];
//           float h = data[3];

//           int left = static_cast<int>((cx - 0.5 * w) * col_factor);
//           int top = static_cast<int>((cy - 0.5 * h) * row_factor);
//           int width = static_cast<int>(w * col_factor);
//           int height = static_cast<int>(h * row_factor);

//           bounding_boxes.push_back(cv::Rect(left, top, width, height));
//         }
//       }

//       data += 85;
//     }

//     std::vector<int> indices;
//     cv::dnn::NMSBoxes(bounding_boxes, confidence_list, SCORE, NMS, indices);
//     for (unsigned int i = 0; i < indices.size(); i++) {
//       int idx = indices[i];
//       cv::Rect box = bounding_boxes[idx];

//       int left = box.x;
//       int top = box.y;
//       int width = box.width;
//       int height = box.height;

//       rectangle(instantaneous_frame, cv::Point(left, top),
//                 cv::Point(left + width, top + height), BLUE, 3 * THICKNESS);

//       std::string bbox = cv::format("%.2f", confidence_list[idx]);
//       bbox = class_name[class_ids[idx]] + ":" + bbox;

//       // Draw bounding box and label using Bbox class
//       Bbox objb;
//       objb.bbox(instantaneous_frame, bbox, left, top);
//     }
//     return instantaneous_frame;
//   }
// };

// #endif  // INCLUDE_POST_PROCESS_HPP_

/**
 * @file post_process.hpp
 * @author Akashkumar Parmar (akasparm@umd.edu)
 * @author Sai Teja Gilukara (saitejag@umd.edu)
 * @brief Class declaration for Postprocess - post processing of the image frame
 * @version 0.1
 * @date 2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

#ifndef INCLUDE_POST_PROCESS_HPP_
#define INCLUDE_POST_PROCESS_HPP_

#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

#include "bbox.hpp"
#include "pre_process.hpp"

class Postprocess : public Preprocess, public Bbox {
 private:
  const float SCORE = 0.5;
  const float NMS = 0.45;
  const float CONFIDENCE = 0.45;
  cv::Scalar BLUE = cv::Scalar(255, 0, 0);
  cv::Scalar RED = cv::Scalar(0, 0, 255);

 public:
  cv::Mat post_process(cv::Mat instantaneous_frame,
                       std::vector<cv::Mat> preprocess_outputs,
                       std::vector<std::string> class_name);
};

#endif  // INCLUDE_POST_PROCESS_HPP_
