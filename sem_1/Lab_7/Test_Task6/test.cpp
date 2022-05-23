#include "pch.h"
unsigned long long solve(unsigned long long n) {
	return ((n % 10 == 9) ? (n / 10 + 1) : (n / 10));
}
TEST(TestCaseName, TestName) {
  EXPECT_EQ(solve(1), 0);
  EXPECT_EQ(solve(9), 1);
  EXPECT_EQ(solve(10), 1);
  EXPECT_EQ(solve(34), 3);
  EXPECT_EQ(solve(880055535), 88005553);
  EXPECT_TRUE(true);
}