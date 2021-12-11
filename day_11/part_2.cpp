#include <vector>

#include "read_input.cpp"
#include "functions.cpp"

int part_2(const std::string& filename) {
	std::vector<std::vector<int>> octopi;
	read_input(filename, octopi);

	bool synced = false;
	int i = 0;
	while (!synced) {
		i++;
		for (int j = 0; j < octopi.size(); j++) {
			for (int k = 0; k < octopi[j].size(); k++) {
				increment_octopus(j, k, octopi);
			}
		}
		synced = true;
		for (int j = 0; j < octopi.size(); j++) {
			for (int k = 0; k < octopi[j].size(); k++) {
				if (octopi[j][k] == -1) {
					octopi[j][k] = 0;
				} else {
					synced = false;
				}
			}
		}
	}

	return i;
}