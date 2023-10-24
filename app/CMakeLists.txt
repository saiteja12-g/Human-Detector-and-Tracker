# Any C++ source files needed to build this target (shell-app).
add_executable(human-detector-tracker
  # list of source cpp files:
  main.cpp
  pose_estimater.cpp
  detector.cpp
  tracker.cpp
  utils.cpp
  )

# Any include directories needed to build this target.
# Note: we do not need to specify the include directories for the
# dependent libraries, they are automatically included.
target_include_directories(human-detector-tracker PUBLIC
  # list inclue directories:
  ${CMAKE_SOURCE_DIR}/include
  ${OpenCV_INCLUDE_DIRS}
)

# Any dependent libraires needed to build this target.
target_link_libraries(human-detector-tracker PUBLIC
  # list of libraries
  ${OpenCV_LIBS}
  )

# target_link_libraries(human-detector-tracker ${OpenCV_LIBS})