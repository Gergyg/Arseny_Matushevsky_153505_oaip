double expected_value(double* arr, int n) {
	double final_sum = 0;
	for (int i = 1; i <= n; i++) {
		final_sum += (1.0 / n) * arr[i];
	}
	return final_sum;
}