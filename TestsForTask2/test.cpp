#include "pch.h"
int Count(double* arr, int left, int right) {
	if (left == right) {
		if (sin((double)arr[left] / 2) < 0) return 1;
		else return 0;
	}
	else return Count(arr, left, (right + left) / 2) + Count(arr, (right + left) / 2 + 1, right);
}
TEST(TestCaseName, TestName) {
	double X[7] = { 0,8,-1,2,4,0,-2 };
  EXPECT_EQ(Count(X,1,6), 3);
  EXPECT_TRUE(true);
}

TEST(TestCaseName2, TestName2) {
	double X[5] = { 0,6.28, 3.14, 1.57, -1.57};
	EXPECT_EQ(Count(X, 1, 4), 1);
	EXPECT_TRUE(true);
}