#include "pch.h"
long long solve(unsigned int k) {
    unsigned int n = floor(double(log(2 * k + 1) / log(3)));

    unsigned int three = 1;
    for (int i = 0; i < n - 1; i++) {
        three *= 3;
    }

    long long result = 0;
    while (k && three) {

        int t = k / three;
        int p = three - 1;
        p = p / 2;
        if (p > k % three) {
            result = result * 10 + k / three - 1;
            k = k % three + three;
        }
        else {

            result = result * 10 + k / three;

            k = k % three;
        }




        three = three / 3;
    }


    return result;
}

TEST(TestCaseName, TestName) {
  EXPECT_EQ(solve(1), 1);
  EXPECT_EQ(solve(2), 2);
  EXPECT_EQ(solve(3), 3);
  EXPECT_EQ(solve(4), 11);
  EXPECT_EQ(solve(5), 12);
  EXPECT_EQ(solve(6), 13);
  EXPECT_EQ(solve(7), 21);
  EXPECT_EQ(solve(8), 22);
  EXPECT_EQ(solve(9), 23);

  EXPECT_EQ(solve(10000), 111123331);
  EXPECT_TRUE(true);
}