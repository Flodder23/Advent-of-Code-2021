#include <map>
#include "read_input.cpp"

struct coord_comp {
	bool operator() (const std::vector<int>& v1, const std::vector<int>& v2) {
		for (int i = 0; i <  v1.size(); i++) {
			if (v1[i] < v2[i]) {
				return true;
			} else if (v1[i] > v2[i]) {
				return false;
			}
		}
		return false;
	}
};

bool update_map(std::map<std::vector<int>, bool, coord_comp>& map, const std::vector<int> coords) {
	if (map.find(coords) == map.end()) {
		map[coords] = false;
	} else {
		if (!map[coords]) {
			map[coords] = true;
			return true;
		} else {
		}
	}
	return false;
}

int part_1(const std::string& filename) {
	// Needs optimising but it will do for the moment
	std::vector<std::vector<std::vector<int>>> vents;
	read_input(filename, vents);

	std::map<std::vector<int>, bool, coord_comp> map;
	int tot_mult = 0; // counts number of coords with multple lines
	std::vector<int> coords;
	for (int i = 0; i < vents.size(); i++) {
		if (vents[i][0][0] == vents[i][1][0]) {
			if (vents[i][0][1] < vents[i][1][1]) {
				for (int j = vents[i][0][1]; j <= vents[i][1][1]; j++) {
					coords = {vents[i][0][0], j};
					if (update_map(map, coords)) {
						tot_mult ++;
					}
				}
			} else {
				for (int j = vents[i][1][1]; j <= vents[i][0][1]; j++) {
					coords = {vents[i][0][0], j};
					if (update_map(map, coords)) {
						tot_mult ++;
					}
				}
			}
		} else if (vents[i][0][1] == vents[i][1][1]){
			if (vents[i][0][0] < vents[i][1][0]) {
				for (int j = vents[i][0][0]; j <= vents[i][1][0]; j++) {
					coords = {j, vents[i][0][1]};
					if (update_map(map, coords)) {
						tot_mult ++;
					}
				}
			} else {
				for (int j = vents[i][1][0]; j <= vents[i][0][0]; j++) {
					coords = {j, vents[i][0][1]};
					if (update_map(map, coords)) {
						tot_mult ++;
					}
				}
			}
		}
	}
	return tot_mult;
}