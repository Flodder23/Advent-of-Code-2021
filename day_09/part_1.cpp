#include <vector>
#include <set>

#include "read_input.cpp"

int part_1(const std::string& filename) {
	std::vector<std::vector<int>> map;
	read_input(filename, map);

	int sum = 0;
	std::set<std::vector<int>> mins;
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			std::vector<std::vector<int>> adj;
			get_adj(i, j, map.size()-1, map[i].size()-1, adj);
			bool is_min = true;
			for (std::vector<int> p : adj) {
				if (map[p[0]][p[1]] <= map[i][j]) {
					is_min = false;
					break;
				}
			}
			if (is_min) {
				sum += map[i][j] + 1;
			}
		}
	}

	return sum;
}