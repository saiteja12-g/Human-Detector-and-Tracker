/**
 * @file main.cpp
 * @author Akashkumar Parmar (akasparm@umd.edu)
 * @author Sai Teja Gilukara (saitejag@umd.edu)
 * @brief Design and Development of the perception module for Acme Robotics
 "Human-detector-and-tracker" This file is responsible for below tasks. Live
 video feed capturing Preprocessing of each frame Human detection and tracking
          Assign label with co-ordinates of Human's positions
          Postprocessing of each frame
 * @version 0.1
 * @date 2023-10-31
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <fstream>
#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>

#include "./../include/post_process.hpp"
#include "./../include/pre_process.hpp"

/**
 * @brief Function to read class names from the file
 *
 * @param file_path Path to the file
 * @return std::vector<std::string>
 */
std::vector<std::string> ReadClassNames(const std::string& file_path) {
  std::vector<std::string> classes;
  std::ifstream ifs(file_path);

  // Read each line from the file and add it to the classes vector
  std::string line;
  while (getline(ifs, line)) {
    classes.push_back(line);
  }

  return classes;
}

/**
 * @brief Main function implementation for loading the object detection class
 list. Takes the live video feed from the camera and processes through
 preprocessing, detection and postprocessing for each image frame. Displays
 result in output window.
 *
 * @return int
 */
int main() {
  // Read class names from a file
  std::vector<std::string> classes =
      ReadClassNames("../app/resources/coco.names");

  // Open a video capture device (e.g., the default camera)
  cv::VideoCapture cap(0);

  // Create a matrix to store each frame
  cv::Mat instantaneous_frame;

  while (true) {
    // Capture a frame from the video source
    cap.read(instantaneous_frame);

    // Load a pre-trained YOLO model
    cv::dnn::Net model =
        cv::dnn::readNet("../app/resources/models/yolov5s.onnx");

    // Perform preprocessing on the frame
    Preprocess pre_obj;
    std::vector<cv::Mat> detections =
        pre_obj.pre_process(instantaneous_frame, model);

    // Perform post-processing to draw bounding boxes and labels on the frame
    Postprocess post_obj;
    cv::Mat img =
        post_obj.post_process(instantaneous_frame.clone(), detections, classes);

    // Display the processed frame in a window
    cv::imshow("Output", img);

    // Wait for a key press (1 ms) and continue to the next frame
    cv::waitKey(1);
  }

  return 0;
}
