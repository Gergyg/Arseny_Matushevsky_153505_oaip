#include "pch.h"
std::string sole(long long n) {
    int dlin = 0;
    std::string result = "";
    if (n == 0) {
        result = "0";
        dlin = 1;
    }
    while (n > 0) {


        dlin++;
        result = char(n % 2 + '0') + result;

        n /= 2;
    }
    for (int k = 0; k < 63 - dlin; k++)
        result = '0' + result;
    return result;
}
TEST(TestCaseName, TestName) {
    EXPECT_EQ(sole(2), "000000000000000000000000000000000000000000000000000000000000010");
    EXPECT_EQ(sole(1024), "000000000000000000000000000000000000000000000000000010000000000");
    EXPECT_EQ(sole(1023), "000000000000000000000000000000000000000000000000000001111111111");
    EXPECT_TRUE(true);
}