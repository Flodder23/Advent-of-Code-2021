#include <vector>

#include "read_input.cpp"
#include "functions.cpp"

int part_1(const std::string& filename) {
	std::vector<std::vector<int>> octopi;
	read_input(filename, octopi);

	int total_flashes = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < octopi.size(); j++) {
			for (int k = 0; k < octopi[j].size(); k++) {
				increment_octopus(j, k, octopi, total_flashes);
			}
		}
		for (int j = 0; j < octopi.size(); j++) {
			for (int k = 0; k < octopi[j].size(); k++) {
				if (octopi[j][k] == -1) {
					octopi[j][k] = 0;
				}
			}
		}
	}

	return total_flashes;
}