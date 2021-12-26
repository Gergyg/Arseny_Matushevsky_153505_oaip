#include "pch.h"
long long f(long long n) {
    if (n % 2 == 1) return n;
    return f(n / 2);
}
long long solve(long long n) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += f(i);
    }
    return sum;
}

TEST(TestCaseName, TestName) {
  EXPECT_EQ(solve(7), 21);
  EXPECT_EQ(solve(1), 1);
  EXPECT_EQ(solve(777), 201537);
  EXPECT_EQ(solve(1000000000), 333333333334181226);
  EXPECT_TRUE(true);
}