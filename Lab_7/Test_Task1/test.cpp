#include "pch.h"
std::string sole(long long n) {
    std::string result = "";
    if (n == 0) return "0";
    while (n > 0) {
        result = char(n % 7 + '0') + result;
        n /= 7;
    }
    return result;
}
TEST(TestCaseName, TestName) {
    
  EXPECT_EQ(sole(7), "10");
  EXPECT_EQ(sole(4654654), "54364264");
  EXPECT_EQ(sole(12112212122121), "2360035623220416");
  EXPECT_EQ(sole(0), "0");
  EXPECT_TRUE(true);
}