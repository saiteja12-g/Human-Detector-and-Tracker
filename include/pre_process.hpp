/**
 * @file pre_process.hpp
 * @author Akashkumar Parmar (akasparm@umd.edu)
 * @author Sai Teja Gilukara (saitejag@umd.edu)
 * @brief Class definition for Preprocess - Preprocessing of each image frame
 * @version 0.1
 * @date 2023-10-31
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef INCLUDE_PRE_PROCESS_HPP_
#define INCLUDE_PRE_PROCESS_HPP_

#include <opencv2/opencv.hpp>
#include <vector>

/**
 * @brief Defines the outline for preprocessing of the each image frame before
 * passing to the model
 *
 */
class Preprocess {
 public:
  const float INPUT_WIDTH = 640.0;
  const float INPUT_HEIGHT = 640.0;

  /**
   * @brief Retrieved video frame is provided as input to yolov5s model and
   * detections are extracted for post-processing.
   *
   * @param instantaneous_frame Instantaneous frame captured by camera
   * @param net Model object
   * @return std::vector<cv::Mat>
   */
  std::vector<cv::Mat> pre_process(cv::Mat instantaneous_frame,
                                   cv::dnn::Net net) {
    cv::Mat blob;
    cv::dnn::blobFromImage(instantaneous_frame, blob, 1. / 255.,
                           cv::Size(INPUT_WIDTH, INPUT_HEIGHT), cv::Scalar(),
                           true, false);

    net.setInput(blob);

    std::vector<cv::Mat> preprocess_outputs;
    net.forward(preprocess_outputs, net.getUnconnectedOutLayersNames());

    return preprocess_outputs;
  }
};

#endif  // INCLUDE_PRE_PROCESS_HPP_
