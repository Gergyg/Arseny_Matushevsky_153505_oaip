#include "pch.h"
void summ(short x[1000], short y[1000]) {
    for (int i = 0; i < 1000; i++) {
        x[i] = x[i] + y[i];
    }
    for (int i = 0; i < 1000; i++) {
        if (x[i] >= 11) {
            int temx = x[i] / 11;
            x[i] = x[i] % 11;
            x[i + 1] += temx;
        }
    }
}
void razn(short x[1000], short y[1000]) {
    for (int i = 0; i < 1000; i++) {
        x[i] = x[i] - y[i];
    }
    for (int i = 0; i < 999; i++) {
        if (x[i] < 0) {
            x[i] = x[i] + 11;
            x[i + 1] -= 1;
        }
    }
}
TEST(TestCaseName, TestName) {
    short a[1000] = { 1,3,5 };
    short b[1000] = { 1,3,5 };
    summ(a, b);
    EXPECT_EQ(a[0], 2);
    EXPECT_EQ(a[1], 6);
    EXPECT_EQ(a[2], 10);
    EXPECT_EQ(a[3], 0);

    short a2[1000] = { 10,10,10 };
    short b2[1000] = { 1 };
    summ(a2, b2);
    EXPECT_EQ(a2[0], 0);
    EXPECT_EQ(a2[1], 0);
    EXPECT_EQ(a2[2], 0);
    EXPECT_EQ(a2[3], 1);
    EXPECT_EQ(a2[4], 0);

    short a3[1000] = { 0,0,0,1 };
    short b3[1000] = { 1 };
    razn(a3, b3);
    EXPECT_EQ(a3[0], 10);
    EXPECT_EQ(a3[1], 10);
    EXPECT_EQ(a3[2], 10);
    EXPECT_EQ(a3[3], 0);
  EXPECT_TRUE(true);
}