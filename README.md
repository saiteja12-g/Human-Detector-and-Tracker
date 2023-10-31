# HUMAN DETECTOR AND TRACKER 

## ENPM 808X Mid-term Project
![CICD Workflow status](https://github.com/saiteja12-g/Human-Detector-and-Tracker/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg)
[![codecov](https://codecov.io/gh/saiteja12-g/Human-Detector-and-Tracker/branch/development_branch_v2/graph/badge.svg)](https://codecov.io/gh/saiteja12-g/Human-Detector-and-Tracker)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

## Student Details

|Name|Sai Teja Gilukara(Driver)|Akash Parmar(Navigator)|
|---|:---:|:---:|
|UID|119369623|118737430|
|Directory ID|saitejag|akasparm|
|Email ID|saitejag@umd.edu|akasparm@umd.edu

## Introduction

The goal of this project is detect and track humans and get the pose estimation from the robot body. This can be useful in industrial warehouses, military applications, safety, security, and entertainment purposes. Finding the locations of all instances of humans, track them frame by frame and get the depth estimation of the human objects is the main aim of this project.

## Dependencies used

|Module|Version|
|---|:---:|
|C++|14|
|OpenCV|Default|
|memory|Default|

## Instructions to run the code

#### Navigate to the repository: 

```  
cd Human-Detector-and-Tracker
```
#### Configure the project and generate a native build system:
  #### Must re-run this command whenever any CMakeLists.txt file has been changed.
  ```
  mkdir build/ && cd build/
  ```

#### Compile and build the project:
  #### rebuild only files that are modified since the last build
  ```
  cmake ..
  make
  ```
#### Run tests:
  ```
  ./test/human-detector-tracker-test
  ```

#### Try out the live feed:
  ```
  ./app/human-detector-tracker
  ```

#### Create Doxygen docs
  ```
  cmake --build build/ --target docs
  ```

## Links

|Item|Link|
|---|:---:|
|Project Proposal Document|[here](/Proposal/Project_Proposal.pdf)|
|Quad Chart|[here](/Proposal/quad%20chart.pdf)|
|UML Diagram|[here](/UML/revised/Revised%20UML_diagram.pdf)|
|Flow Chart|[here](/Proposal/Flowchart.pdf)|
|AIP Sheet|[here](https://docs.google.com/spreadsheets/u/0/d/1XzHJKPvlp2NBZCuSRj7cfIvq3t03doPlDkwKnDLFQbU/edit?pli=1#gid=1967651968)|
|Videos|[here](https://drive.google.com/drive/folders/1_GK_JMNFahxSQeobAj8jg4wJFANAf9b8?usp=sharing)|
