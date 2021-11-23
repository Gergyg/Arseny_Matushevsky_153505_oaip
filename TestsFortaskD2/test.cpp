#include "pch.h"
unsigned long long solve(unsigned long long x, unsigned long long y, unsigned long long n) {
    if (y == 0) return 1;
    if (y % 2 == 1) return (x * solve((x * x) % n, y / 2, n)) % n;
    return solve((x * x) % n, y / 2, n);
}
TEST(TestCaseName, TestName) {
  EXPECT_EQ(solve(1234,1234, 10000),736);
  EXPECT_EQ(solve(888, 888, 100000000), 91255296);
  EXPECT_TRUE(true);
}