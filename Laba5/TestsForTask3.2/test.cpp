#include "pch.h"
void permutation(double**& a, int x, int y) {
    int flag = (x * y + 1) / 2;
    int kol = 0;
    for (int i = 0; i < x && kol < flag; i++) {
        for (int j = 0; j < y && kol < flag; j++) {
            kol++;
            double t = a[i][j];
            a[i][j] = a[x - i - 1][y - j - 1];
            a[x - i - 1][y - j - 1] = t;
        }
    }
}
TEST(TestCaseName, TestName) {
    double ** A = new double* [2];
    for (int i = 0; i < 2; i++) {
        A[i] = new double[3];
    }
    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = 3;
    A[1][0] = 7;
    A[1][1] = 4;
    A[1][2] = 5;
    permutation(A, 2, 3);
    EXPECT_EQ(A[0][0], 5);
    EXPECT_EQ(A[0][1], 4);
    EXPECT_EQ(A[0][2], 7);
    EXPECT_EQ(A[1][0], 3);
    EXPECT_EQ(A[1][1], 2);
    EXPECT_EQ(A[1][2], 1);
    for (int i = 0; i < 2; i++) {
        delete[] A[i];
    }
}