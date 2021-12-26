#include "pch.h"
int solve(int** a, int x, int y, int*& c) {
    int size = 0;
    for (int j = 1; j < y; j += 2) {
        for (int i = 0; i < x; i++) {
            if (a[i][j] % 2 == 1) {
                c[size] = a[i][j];
                size++;
            }
        }
    }
    return size;
}
TEST(TestCaseName, TestName) {
    int** A = new int* [2];
    for (int i = 0; i < 2; i++) {
        A[i] = new int[3];
    }
    A[0][0] = 2;
    A[0][1] = 3;
    A[0][2] = 2;
    A[1][0] = 7;
    A[1][1] = 7;
    A[1][2] = 5;
    int* g = new int[2];
    solve(A, 2, 3, g);
    EXPECT_EQ(g[0], 3);
    EXPECT_EQ(g[1], 7);
    for (int i = 0; i < 2; i++) {
        delete[] A[i];
    }
}