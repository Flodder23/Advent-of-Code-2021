#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

#include "read_input.cpp"

void part_1() {
	std::vector<std::vector<int>> input;
	read_input(input);
	int len = input[0].size();
	std::vector<int> num_zeros(len, 0);

	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < len; j++) {
			if (input[i][j] == 0) {
				num_zeros[j] ++;
			}
		}
	}

	int gamma = 0, epsilon = 0;
	for (int i = 0; i < len; i++) {
		if (input.size() > 2*num_zeros[i]) {
			gamma += std::pow(2, len - i - 1);
		} else {
			epsilon += std::pow(2, len - i - 1);
		}
	}

	std::cout << gamma * epsilon;
}