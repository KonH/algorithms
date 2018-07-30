#include "utils.h"

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void insertion_sort(int array[], int size) {
	for ( int i = 1; i < size; i++ ) {
		int j = i;
		while ( (j > 0) && (array[j] < array[j - 1]) ) {
			swap(&array[j], &array[j - 1]);
			j = j - 1;
		}
	}
}

int main() {
	int n = 7;
	int array[]    = {  5, 10, 15, 8, 6,  1, -1 };
	int expected[] = { -1,  1,  5, 6, 8, 10, 15 };
	insertion_sort(array, n);
	return assert_equals_arr(array, expected, n);
}

