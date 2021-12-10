#include <vector>
#include <set>

#include "read_input.cpp"

int part_2(const std::string& filename) {
	std::vector<std::vector<int>> map;
	read_input(filename, map);

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
				mins.insert({i, j});
			}
		}
	}

	std::vector<int> big_sizes(3, 0);
	for (std::vector<int> min : mins) {
		std::set<std::vector<int>> basin({min}), last_pass({min}), this_pass({min});
		while (last_pass.size() > 0) {
			last_pass = this_pass;
			this_pass.clear();
			for (std::vector<int> point : last_pass) {
				std::vector<std::vector<int>> adj;
				get_adj(point[0], point[1], map.size()-1, map[point[0]].size()-1, adj);
				for (std::vector<int> p : adj) {
					if (map[p[0]][p[1]] != 9 &&
						this_pass.find(p) == this_pass.end() &&
						basin.find(p) == basin.end()
					) {
						this_pass.insert(p);
						basin.insert(p);
					}
				}
			}
		}
		int s = basin.size();
		for (int i = 0; i < big_sizes.size(); i++) {
			if (s > big_sizes[i]) {
				int t = s;
				s = big_sizes[i];
				big_sizes[i] = t;
			}
		}
	}

	return big_sizes[0] * big_sizes[1] * big_sizes[2];
}