#include <iostream>
#include <vector>
#include <string>

#include "read_input.cpp"

void part_2() {
	int x = 0, y = 0, a = 0; // x is across, y is down
	std::vector<std::string> direction;
	std::vector<int> length;
	read_input(direction, length);

	for (int i = 0; i < direction.size(); i++) {
		if      (direction[i] == "d") { a += length[i]; }
		else if (direction[i] == "u") { a -= length[i]; }
		else if (direction[i] == "f") {
			x += length[i];
			y += a * length[i];
		}
	}

	std::cout << x*y;
}