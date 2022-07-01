//
// Created by postonlylosses on 1/07/22.
//
#include "RollingAverageTracker.h"

class RollingAverageTrackerTests: public ::testing::Test { };

TEST_F(RollingAverageTrackerTests, testAccuracy){
    RollingAverageTracker<int> rat(100);

    for(int i = 0; i < 10; ++i){
        rat.add_node(9);
    }

    for(int i = 0; i < 100; ++i){
        rat.add_node(10);
    }

    ASSERT_EQ(rat.get_average(), 10);
}

TEST_F(RollingAverageTrackerTests, testHugeNumber){
    RollingAverageTracker<uint64_t> rat(999999999999999999);
    rat.add_node(5);
    rat.add_node(5);
    ASSERT_EQ(rat.get_average(), 5);
}

TEST_F(RollingAverageTrackerTests, edgeCases){
    RollingAverageTracker<int> rat(0);
    rat.add_node(5);
    ASSERT_EQ(rat.get_average(), 5);
}

TEST_F(RollingAverageTrackerTests, testWrong){
    RollingAverageTracker<double> rat(10000);

    for(int i = 0; i < 10000; ++i){
        rat.add_node(5);
    }

    rat.add_node(4);
    ASSERT_NE(rat.get_average(), 5);
}
