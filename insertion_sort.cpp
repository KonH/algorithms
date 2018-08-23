#include <array>

#include "utils.h"

using std::array;

void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

template<size_t Size>
void insertion_sort(array<int, Size>& array) {
	for ( size_t i = 1; i < array.size(); i++ ) {
		int j = i;
		while ( (j > 0) && (array[j] < array[j - 1]) ) {
			swap(array[j], array[j - 1]);
			j = j - 1;
		}
	}
}

int main() {
	array<int, 7> arr      = {{  5, 10, 15, 8, 6,  1, -1 }};
	array<int, 7> expected = {{ -1,  1,  5, 6, 8, 10, 15 }};
	insertion_sort(arr);
	return assert_equals(arr, expected);
}

