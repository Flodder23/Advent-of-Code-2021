#include <iostream>

#include "read_input.cpp"

int part_2(const std::string& filename) {
	std::vector<int> input;
	read_input(filename, input);
	int tot_increase = 0;
	for (int i = 3; i < input.size(); i++) {
		// if we are checking if a+b+c < b+c+d
		// we can actually just check if a < d
		if (input[i-3] < input[i]) {
			tot_increase ++;
		}
	}
	return tot_increase;
}