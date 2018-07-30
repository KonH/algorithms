#include "utils.h"
#include <math.h>
#include <float.h>
#include <stdbool.h>

typedef struct {
	int x;
	int y;
} Point;

double get_distance(Point p1, Point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

bool is_found_in_passed(int passed[], int passed_size, int index) {
	int found_in_passed = 0;
	for ( int j = 0; j < passed_size; j++ ) {
		if ( passed[j] == index ) {
			return true;
		}
	}
	return false;
}

int select_nearest_point(Point points[], int size, int passed[], int passed_size, int cur_index) {
	int nearest_index = -1;
	double nearest_distance = DBL_MAX;
	for ( int i = 0; i < size; i++ ) {
		if ( i == cur_index ) {
			continue;
		}
		if ( is_found_in_passed(passed, passed_size, i) ) {
			continue;
		}
		double cur_distance = get_distance(points[cur_index], points[i]);
		if ( cur_distance < nearest_distance ) {
			nearest_distance = cur_distance;
			nearest_index = i;
		}
	}
	return nearest_index;
}

void nearest_neighbor(Point points[], int size, int start_index, int passed[], int result[]) {
	int i = 0;
	int nearest = 0;
	int cur_index = start_index;
	for ( int i = 0; i < size - 1; i++ ) {
		nearest = select_nearest_point(points, size, passed, i, cur_index);
		result[i] = nearest;
		passed[i] = cur_index;
		cur_index = nearest;
	}
	result[size - 1] = start_index;
}

int main() {
	const int size = 4;
	Point points[size] = { {1, 1}, {5, 5}, {2, 3}, {7, 3} };
	int expected[size] = { 2, 1, 3, 0 };
	int passed  [size] = { 0 };
	int result  [size] = { 0 };
	nearest_neighbor(points, size, 0, passed, result);
	return assert_equals_arr(expected, result, size);
}
