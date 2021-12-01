#include <iostream>

#include "read_input.cpp"

void part_1() {
	std::vector<int> input;
	read_input(input);

	int tot_increase = 0;
	for (int i = 1; i < input.size(); i++) {
		if (input[i-1] < input[i]) {
			tot_increase ++;
		}
	}
	
	std::cout << tot_increase;
}