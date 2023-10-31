#include <fstream>
#include <opencv2/opencv.hpp>

// #include "./../include/bbox.hpp"
#include "./../include/post_process.hpp"
#include "./../include/pre_process.hpp"

int main() {
  std::vector<std::string> class_list;
  std::ifstream ifs("../app/resources/coco.names");
  std::string line;

  while (getline(ifs, line)) {
    class_list.push_back(line);
  }

  cv::VideoCapture cap(0);
  cv::Mat video_frame;

  while (true) {
    cap.read(video_frame);

    cv::dnn::Net model;
    model = cv::dnn::readNet("./../app/resources/models/yolov5s.onnx");

    std::vector<cv::Mat> detections;
    Preprocess pre_obj;
    detections = pre_obj.pre_process(video_frame, model);

    Postprocess post_obj;
    cv::Mat img =
        post_obj.post_process(video_frame.clone(), detections, class_list);

    cv::imshow("Output", img);
    cv::waitKey(1);
  }
  return 0;
}
