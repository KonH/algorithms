#include <stdio.h>

void print_array(int array[], int size) {
	for ( int i = 0; i < size; i++ ) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

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
	int array[] = { 5, 10, 15, 8, 6, 1, -1 };
	insertion_sort(array, n);
	print_array(array, 7);
	return 0;
}

