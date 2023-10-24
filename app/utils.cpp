#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include <../include/utils.hpp>

cv::Mat acme_robotics::Utils::GetBB(cv::Mat i, const cv::Rect &b, const std::string &l) {
    cv::Mat frame = i.clone();
    cv::Scalar color = cv::Scalar(0, 0, 255);
    cv::Scalar l_color = cv::Scalar::all(255);

    int f_face(0);

    double f_scale(1);

    cv::Point l_pt;
    cv::Point top_pt;
    cv::Point bottom_pt;
    int b_line(0);
    cv::Size l_size;
    cv::rectangle(frame, b, color, 2, cv::LINE_AA);
    l_size = cv::getTextSize(l, f_face, f_scale, 2, &b_line);
    top_pt = cv::Point(b.x, b.y);
    bottom_pt = cv::Point(b.x + l_size.width, b.y + l_size.height);
    l_pt = cv::Point(b.x, b.y);
    cv::rectangle(frame, top_pt, bottom_pt, color, -1, 16);
    cv::putText(frame, l, l_pt, f_face, f_scale, l_color, 2);
    return frame;
}

cv::Point acme_robotics::Utils::TrackNextPoint(const cv::Rect &bbox) {
    int x_center = bbox.width / 2 + bbox.x;
    int y_center = bbox.height / 2 + bbox.y;
    return cv::Point(x_center, y_center);
}

acme_robotics::Pose acme_robotics::Utils::PixelsToDepth(const cv::Rect &b, double calib_factor) {
    double height = b.height;
    double calib_distance = calib_factor / height;
    cv::Point centre = acme_robotics::Utils::TrackNextPoint(b);

    return acme_robotics::Pose(calib_distance, centre.x, centre.y);
}

