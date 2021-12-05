#include <iostream>

#include "read_input.cpp"

int part_1(const std::string& filename) {
	std::vector<int> input;
	read_input(filename, input);

	int tot_increase = 0;
	for (int i = 1; i < input.size(); i++) {
		if (input[i-1] < input[i]) {
			tot_increase ++;
		}
	}
	
	return tot_increase;
}