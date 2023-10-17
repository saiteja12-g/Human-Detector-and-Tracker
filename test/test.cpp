#include <gtest/gtest.h>


TEST(dummy_test, this_should_pass) {
  EXPECT_EQ(1, 1);
}

TEST(dummy_test, this_should_pass_too) {
  EXPECT_EQ(my_function1(3), 3);
}
