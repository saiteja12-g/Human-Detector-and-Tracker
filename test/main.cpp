/**
 * @file main.cpp
 * @brief Main entry point for running unit tests
 *
 * This file serves as the main entry point for running unit tests using the
 * Google Test framework. It initializes the testing framework and runs all
 * defined test cases.
 *
 * @author Akashkumar Parmar (Driver) (akasparm@umd.edu)
 * @author Sai Teja Gilukara (Navigator) (saitejag@umd.edu)
 * @version 0.1
 * @date 2023-10-24
 *
 * @copyright Copyright (c) 2023
 */

#include <gtest/gtest.h>

int main(int argc, char** argv) {
  // Initialize the Google Test framework with command-line arguments
  ::testing::InitGoogleTest(&argc, argv);

  // Run all defined test cases
  return RUN_ALL_TESTS();
}
