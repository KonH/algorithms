#include <stdio.h>

// Print extensions

void print_array(int array[], int size) {
	for ( int i = 0; i < size; i++ ) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int assert_equals_arr(int actual[], int expected[], int size) {
	for ( int i = 0; i < size; i++ ) {
		if ( actual[i] != expected[i] ) {
			printf("Assert: failed!\n");
			print_array(actual, size);
			printf("!=\n");
			print_array(expected, size);
			return 1;
		}
	}
	printf("Assert: passed\n");
	return 0;
}
