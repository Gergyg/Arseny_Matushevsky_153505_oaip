#include "pch.h"
#include <iostream>
#include <iomanip>
double Dispertion(double* arr, int n, double m) {
	double final_sum = 0;
	for (int i = 1; i <= n; i++) {
		final_sum = (1.0 / n) * (arr[i] - m) * (arr[i] - m);
	}
	return final_sum;
}
double expected_value(double* arr, int n) {
	double final_sum = 0;
	for (int i = 1; i <= n; i++) {
		final_sum += (1.0 / n) * arr[i];
	}
	return final_sum;
}
TEST(TestCaseName1, TestName1) {
	double arr[6] = {0, 0.412283, 0.20945, 49.2138, 0.745962, 0.0875053 };
  EXPECT_NEAR(expected_value(arr,5), 10.1338,0.0001);
  EXPECT_NEAR(Dispertion(arr, 5, expected_value(arr, 5)), 20.1856,0.0001);
  EXPECT_TRUE(true);
}
TEST(TestCaseName2, TestName2) {
	double arr[5] = { 0, 0.412283, 0.20945, 49.2138, 0.745962 };
	EXPECT_NEAR(expected_value(arr, 4), 12.6454, 0.0001);
	EXPECT_NEAR(Dispertion(arr, 4, expected_value(arr, 4)), 35.399, 0.0001);
	EXPECT_TRUE(true);
}