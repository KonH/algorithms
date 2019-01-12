#pragma once

#include "utils.h"

namespace optimal_scheduling {
	struct time_frame {
		int index;
		int start_time;
		int end_time;
	};
	
	time_frame find_earliest_end_frame(const vector<time_frame>& all_frames) {
		auto end_time = std::numeric_limits<int>::max();
		time_frame result { -1, 0, 0 };
		for ( auto i = 0; i < all_frames.size(); i++ ) {
			auto frame = all_frames[i];
			if ( frame.end_time < end_time ) {
				end_time = frame.end_time;
				result = frame;
			}
		}
		return result;
	}
	
	bool is_crossing(time_frame f1, time_frame f2) {
		return !( (f1.end_time <= f2.start_time) || (f2.end_time <= f1.start_time) );
	}
	
	void remove_all_crossing_frames(vector<time_frame>& all_frames, time_frame f1) {
		auto iter = std::remove_if(
			all_frames.begin(),
			all_frames.end(),
			[f1](time_frame f2) {
				return is_crossing(f1, f2);
			}
		);
		all_frames.erase(iter, all_frames.end());
	}
	
	vector<int> get_optimal_schedule(vector<time_frame> all_frames) {
		vector<int> result;
		while ( all_frames.size() > 0 ) {
			auto frame = find_earliest_end_frame(all_frames);
			result.push_back(frame.index);
			remove_all_crossing_frames(all_frames, frame);
		}
		return result;
	}
	
	void run() {
		vector<time_frame> all_frames = {
			time_frame { 0, 0, 3 }, time_frame { 1, 4, 9 },
			time_frame { 2, 1, 4 }, time_frame { 3, 7, 9 },
			time_frame { 4, 0, 2 }, time_frame { 5, 4, 6 }, time_frame { 6, 8, 10 }
		};
		vector<int> expected = { 4, 5, 3 };
		auto result = get_optimal_schedule(all_frames);
		assert_equals(result, expected);
	}
}
