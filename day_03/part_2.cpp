#include <iostream>
#include <vector>
#include <cmath>

#include "read_input.cpp"

int bin_to_dec(const std::vector<int>& num) {
	int result = 0;
	for (int i = 0; i < num.size(); i++) {
		if (num[num.size() - i - 1] == 1) {
			result += std::pow(2, i);
		}
	}
	return result;
}

int index_of_rating(const std::vector<std::vector<int>>& report, int mode) {
	std::vector<int> indices(report.size(), 1);
	int num_left = indices.size();

	for (int j = 0; j < report[0].size(); j++) {
		int num_ones = 0;
		for (int i = 0; i < report.size(); i++) {
			if (indices[i] == 1) {
				if (report[i][j] == 1) {
					num_ones ++;
				}
			}
		}

		int filter;
		if (num_left <= 2*num_ones) { filter = mode; }
		else { filter = 1-mode; }

		num_left = 0;
		int last_index = -1;
		for (int i = 0; i < indices.size(); i++) {
			if (indices[i] == 1) {
				if (report[i][j] != filter) {
					indices[i] = 0;
				} else {
					num_left ++;
					last_index = i;
				}
			}
		}
		if (num_left == 1) { return last_index; }
	}
	return -1;
}

int part_2(const std::string& filename) {
	std::vector<std::vector<int>> input;
	read_input(filename, input);
	int len = input[0].size();

	int oxy_ind = index_of_rating(input, 1);
	int co2_ind = index_of_rating(input, 0);

	int oxy = bin_to_dec(input[oxy_ind]);
	int co2 = bin_to_dec(input[co2_ind]);

	return oxy * co2;
}