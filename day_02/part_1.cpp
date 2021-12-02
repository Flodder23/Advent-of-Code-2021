#include <iostream>
#include <vector>
#include <string>

#include "read_input.cpp"

void part_1() {
	int x = 0, y = 0; // x is across, y is down
	std::vector<std::string> direction;
	std::vector<int> length;
	read_input(direction, length);

	for (int i = 0; i < direction.size(); i++) {
		if      (direction[i] == "f") { x += length[i]; }
		else if (direction[i] == "d") { y += length[i]; }
		else if (direction[i] == "u") { y -= length[i]; }
	}

	std::cout << x*y;
}