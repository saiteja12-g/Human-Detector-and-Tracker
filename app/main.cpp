#include <fstream>
#include <opencv2/opencv.hpp>

// #include "./../include/bbox.hpp"
#include "./../include/post_process.hpp"
#include "./../include/pre_process.hpp"

int main() {
  std::vector<std::string> classes;
  std::ifstream ifs("../app/resources/coco.names");
  std::string line;

  while (getline(ifs, line)) {
    classes.push_back(line);
  }

  cv::VideoCapture cap(0);
  cv::Mat instantaneous_frame;

  while (true) {
    cap.read(instantaneous_frame);

    cv::dnn::Net model;
    model = cv::dnn::readNet("./../app/resources/models/yolov5s.onnx");

    std::vector<cv::Mat> detections;
    Preprocess pre_obj;
    detections = pre_obj.pre_process(instantaneous_frame, model);

    Postprocess post_obj;
    cv::Mat img =
        post_obj.post_process(instantaneous_frame.clone(), detections, classes);

    cv::imshow("Output", img);
    cv::waitKey(1);
  }
  return 0;
}
