double Dispertion(double* arr, int n, double m) {
	double final_sum = 0;
	for (int i = 1; i <= n; i++) {
		final_sum = (1.0 / n) * (arr[i] - m) * (arr[i] - m);
	}
	return final_sum;
}