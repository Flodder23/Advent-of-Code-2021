#include <iostream>

#include "read_input.cpp"

void part_2() {
	std::vector<int> input;
	read_input(input);
	int tot_increase = 0;
	for (int i = 3; i < input.size(); i++) {
		// if we are checking if a+b+c < b+c+d
		// we can actually just check if a < d
		if (input[i-3] < input[i]) {
			tot_increase ++;
		}
	}
	std::cout << tot_increase;
}