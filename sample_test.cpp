#include "gtest/gtest.h"
#include "isodd.h"

class IsOddTrueTest : public ::testing::TestWithParam<int>{};

TEST_P(IsOddTrueTest, positiveTest) {
    int n = GetParam();
    printf("値：%d\n", n);
    EXPECT_TRUE(IsOdd(n));
}

INSTANTIATE_TEST_CASE_P(
    ParamTest, 
    IsOddTrueTest,
    ::testing::Range(1, 10, 2)
);
