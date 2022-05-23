#include "pch.h"
int subtract(unsigned int x, unsigned int y) {
    while (y) {
        unsigned int borrow = (~x) & y;

        x = x ^ y;

        y = borrow << 1;
    }
    return x;
}

unsigned int inc(unsigned int i) {
    unsigned int mask = 1;
    while (i & mask) {
        i &= ~mask;
        mask <<= 1;
    }
    i |= mask;
    return i;
}

unsigned int divide(unsigned int n, unsigned int d) {
    unsigned int q = 0;

    while (n >= d) {
        unsigned int i = 0, d_t = d;

        while (n >= (d_t << 1)) {
            i = inc(i);
            d_t <<= 1;
        }

        q |= 1 << i;

        n = subtract(n, d_t);
    }
    return q;
}

int add(unsigned int x, unsigned int y) {
    while (y) {
        unsigned int carry = x & y;

        x = x ^ y;

        y = carry << 1;
    }
    return x;
}

unsigned int multiply(unsigned int a, unsigned int b) {
    unsigned int result = 0;
    while (b)
    {
        if (b & 01)
        {
            result = add(result, a);
        }
        a <<= 1;
        b >>= 1;
    }
    return result;
}

unsigned int mod(unsigned int a, unsigned int b) {
    unsigned int r = divide(a, b);
    return subtract(a, multiply(r, b));
}



TEST(TestCaseName, TestName) {
  EXPECT_EQ(add(251,912), 1163);
  EXPECT_EQ(multiply(21, 84), 1764);
  EXPECT_EQ(divide(154, 3), 51); 
  EXPECT_EQ(mod(154, 3), 1);
  EXPECT_EQ(divide(154, 155), 0);
  EXPECT_EQ(mod(154, 155), 154);
  EXPECT_TRUE(true);
}