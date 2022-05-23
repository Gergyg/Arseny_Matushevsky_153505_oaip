#include <cmath>
extern "C" __declspec(dllexport) int Count(double* arr, int left, int right) {
	if (left == right) {
		if (sin((double)arr[left] / 2) < 0) return 1;
		else return 0;
	}
	else return Count(arr, left, (right+left) / 2) + Count(arr, (right+left) / 2 + 1, right);

	
}