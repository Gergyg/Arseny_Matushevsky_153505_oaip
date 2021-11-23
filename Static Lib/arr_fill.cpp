#include <cmath>
void arr_fill(double*& arr, int n) {
	for (int i = 1; i <= n; i++) {
		if (i <= 17) {
			arr[i] = (1.0 / tan(i)) * (1.0 / tan(i));
		}
		else {
			arr[i] = sin(i);
		}
	}
}