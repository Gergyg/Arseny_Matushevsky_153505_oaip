#include "pch.h"
int diag(int** b, int x, int y, int*& c) {
    int razm = 0;
    for (int i = 0; i < (x < y ? x : y); i++) {
        if (b[i][i] % 2 == 0) c[razm++] = b[i][i];
    }
    return razm;
}
int compos(int* c, int r) {
    int res = 1;
    for (int i = 0; i < r; i++) {
        res *= c[i];
    }
    return res;
}
TEST(TestCaseName, TestName) {
    int** A = new int* [2];
    for (int i = 0; i < 2; i++) {
        A[i] = new int[3];
    }
    A[0][0] = 2;
    A[0][1] = 2;
    A[0][2] = 2;
    A[1][0] = 7;
    A[1][1] = 4;
    A[1][2] = 5;
    int* g = new int[2];
    int size = diag(A, 2, 3, g);
    int c = compos(g, size);
  EXPECT_EQ(size, 2);
  EXPECT_EQ(g[0], 2);
  EXPECT_EQ(g[1], 4);
  EXPECT_EQ(c, 8);
  
  EXPECT_TRUE(true);

  for (int i = 0; i < 2; i++) {
      delete[] A[i];
  }
  delete[] g;
}