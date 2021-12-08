#include <vector>
#include <iostream>

#include "read_input.cpp"
#include "functions.cpp"

int part_1(const std::string& filename) {
	std::vector<std::vector<std::vector<int>>> vents;
	read_input(filename, vents);

	std::vector<std::vector<int>> map(1000, std::vector<int>(1000, 0));
	std::vector<int> coords, coords_0, coords_1;
	int tot_mult = 0;
	for (int i = 0; i < vents.size(); i++) {
		generate_coords(vents[i][0], vents[i][1], coords_0, coords_1);
		if (coords_0[0] != coords_0[1] && coords_1[0] != coords_1[1]) { continue; }
		for (int j = 0; j < coords_0.size(); j++) {
			int& pos = map.at(coords_0[j]).at(coords_1[j]);
			pos ++;
			if (pos == 2) {
				tot_mult ++;
			}
		}
	}
	return tot_mult;
}