#include <gtest/gtest.h>

namespace {
    int InitialTest () { return true; }
}

TEST(TestTopic, TrivialEquality) {
    EXPECT_EQ(InitialTest(), true);
}

//TEST(TestTopic, TrivialEqualityFail) {
//    ASSERT_EQ(InitialTest(), false) << "Oh no, a mistake!";
//    EXPECT_FLOAT_EQ(23.23F, 23.23F);
//}

