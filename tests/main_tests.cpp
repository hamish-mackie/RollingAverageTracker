//
// Created by postonlylosses on 1/07/22.
//

// main_test.cc
#include <gtest/gtest.h>

#include "RollingAverageTrackerTests.cpp"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}