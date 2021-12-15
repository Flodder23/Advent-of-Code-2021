#include "read_input.cpp"

int part_1(const std::string& filename) {
	std::vector<std::vector<int>> map;
	read_input(filename, map);
	std::vector<std::vector<int>> risk(map.size(), std::vector<int>(map[0].size(), -1));
	std::vector<std::vector<bool>> complete(map.size(), std::vector<bool>(map[0].size(), false));
	risk[0][0] = 0;

	std::pair<int, int> point = {0, 0};
	while (!(point.first == map.size()-1 && point.second == map[0].size()-1)) {
		complete[point.first][point.second] = true;
		std::vector<std::pair<int, int>> adj;
		get_adj(point.first, point.second, map.size()-1, map[0].size()-1, adj);
		for (std::pair<int, int> p : adj) {
			if (
				!complete[p.first][p.second] && (
					risk[p.first][p.second] == -1 ||
					map[p.first][p.second] + risk[point.first][point.second] < risk[p.first][p.second]
				)
			) {
				risk[p.first][p.second] = map[p.first][p.second] + risk[point.first][point.second];
			}
		}
		int min_val = -1;
		for (int x = 0; x < map.size(); x++) {
			for (int y = 0; y < map[x].size(); y++) {
				if (!complete[x][y] && risk[x][y] != -1 && (min_val == -1 || risk[x][y] < min_val)) {
					min_val = risk[x][y];
					point.first = x;
					point.second = y;
				}
			}
		}
	}

	return risk[point.first][point.second];
}