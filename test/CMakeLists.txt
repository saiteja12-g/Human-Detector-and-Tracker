# Any C++ source files needed to build this target (human-detector-tracker-test).
add_executable(human-detector-tracker-test
  # list of source cpp files:
  main.cpp
  test.cpp
  )


include_directories(
    ${OpenCV_INCLUDE_DIRS}
)

# Any include directories needed to build this target.
# Note: we do not need to specify the include directories for the
# dependent libraries, they are automatically included.
target_include_directories(human-detector-tracker-test PUBLIC
  # list of include directories:
  ${CMAKE_SOURCE_DIR}/include
  ${OpenCV_LIBS}
  )

# Any dependent libraires needed to build this target.
target_link_libraries(human-detector-tracker-test PUBLIC
  # list of libraries:
  gtest
  ${OpenCV_LIBS}
  )

# Enable CMake’s test runner to discover the tests included in the
# binary, using the GoogleTest CMake module.
gtest_discover_tests(human-detector-tracker-test)

