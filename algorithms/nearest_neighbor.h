#include "utils.h"

using std::array;
using std::vector;

namespace nearest_neighbor {
	bool is_found_in_passed(const vector<size_t>& passed, const size_t index) {
		for ( auto p : passed ) {
			if ( p == index ) {
				return true;
			}
		}
		return false;
	}

	template<size_t Size>
	size_t select_nearest_point(const array<Point, Size>& points, const vector<size_t>& passed, const size_t cur_index) {
		size_t nearest_index = -1;
		double nearest_distance = std::numeric_limits<double>::max();
		for ( size_t i = 0; i < points.size(); i++ ) {
			if ( i == cur_index ) {
				continue;
			}
			if ( is_found_in_passed(passed, i) ) {
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

	template<size_t Size>
	vector<size_t> nearest_neighbor(const array<Point, Size>& points, const size_t start_index) {
		vector<size_t> result;
		vector<size_t> passed;
		size_t nearest = 0;
		size_t cur_index = start_index;
		for ( size_t i = 0; i < points.size() - 1; i++ ) {
			nearest = select_nearest_point(points, passed, cur_index);
			result.push_back(nearest);
			passed.push_back(cur_index);
			cur_index = nearest;
		}
		result.push_back(start_index);
		return result;
	}

	void run() {
		array<Point, 4> points = {{ {1, 1}, {5, 5}, {2, 3}, {7, 3} }};
		vector<size_t> expected = { 2, 1, 3, 0 };
		auto result = nearest_neighbor<4>(points, 0);
		assert_equals(result, expected);
	}
}
