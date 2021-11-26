#include "gtest/gtest.h"

#include "movieSingleton_test.h"
#include "sortstrategy_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
