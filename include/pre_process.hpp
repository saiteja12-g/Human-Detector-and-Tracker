#ifndef INCLUDE_PRE_PROCESS_HPP_
#define INCLUDE_PRE_PROCESS_HPP_

#include <opencv2/opencv.hpp>
#include <vector>

class Preprocess {
 public:
  const float INPUT_WIDTH = 640.0;
  const float INPUT_HEIGHT = 640.0;

  std::vector<cv::Mat> pre_process(cv::Mat input_frame, cv::dnn::Net net) {
    cv::Mat blob;
    cv::dnn::blobFromImage(input_frame, blob, 1. / 255.,
                           cv::Size(INPUT_WIDTH, INPUT_HEIGHT), cv::Scalar(),
                           true, false);

    net.setInput(blob);

    std::vector<cv::Mat> preprocess_outputs;
    net.forward(preprocess_outputs, net.getUnconnectedOutLayersNames());

    return preprocess_outputs;
  }
};

#endif  // INCLUDE_PRE_PROCESS_HPP_
