#include "pch.h"

int F(int n) {
    if (n % 10 > 0)
        return n % 10;
    if (n == 0)
        return 0;
    return F(n / 10);
}
int solve(int x, int y) {
    int result = 0;
    for (int i = x; i <= y; i++)
        result += F(i);
    return result;
}
TEST(TestCaseName, TestName) {
    EXPECT_EQ(solve(1, 10), 46);
    EXPECT_EQ(solve(10, 20), 48);
    EXPECT_EQ(solve(30, 40), 52);
    EXPECT_EQ(solve(72, 58), 0);
    EXPECT_EQ(solve(96, 132), 175);
    EXPECT_EQ(solve(1, 214748364), 1073741750);
  EXPECT_TRUE(true);
}