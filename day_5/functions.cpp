#ifndef FUNCTIONS_CPP
#define FUNCTIONS_CPP

#include <vector>
#include <iostream>

void range(int start, int end, std::vector<int>& result) {
	// return numbers in given range (inclusive endpoints)
	int d = (start < end)? 1 : -1;
	int len = d * (end-start) + 1;
	result.assign(len, 0);
	for (int i = 0; i <= len; i++) {
		result[i] = start + d*i;
	}
}

void generate_coords(const std::vector<int>& start, const std::vector<int>& end, std::vector<int>& result_0, std::vector<int>& result_1) {
	if (start[0] == end[0]) {
		range(start[1], end[1], result_1);
		result_0.assign(result_1.size(), start[0]);
	} else if (start[1] == end[1]) {
		range(start[0], end[0], result_0);
		result_1.assign(result_0.size(), end[1]);
	} else {
		range(start[0], end[0], result_0);
		range(start[1], end[1], result_1);
	}
}

#endif