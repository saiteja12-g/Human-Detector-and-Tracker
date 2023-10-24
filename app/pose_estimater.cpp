#include <algorithm>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include <../include/pose_estimater.hpp>
#include <optional>

acme_robotics::pose_estimater::pose_estimater(){

}

acme_robotics::pose_estimater::~pose_estimater(){}

double acme_robotics::pose_estimater::FindDepth(){
    return true;
}

double acme_robotics::pose_estimater::DepthToPose(){
    return false;
}