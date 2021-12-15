#include "read_input.cpp"

int part_2(const std::string& filename) {
	std::vector<std::vector<int>> map_small;
	read_input(filename, map_small);

	int len0 = map_small.size(), len1 = map_small[0].size();
	std::vector<std::vector<int>>map(len0*5, std::vector<int>(len1*5));

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int x = 0; x < len0; x++) {
				for (int y = 0; y < len1; y++) {
					map[i*len0 + x][j*len1 + y] = 1 + ((map_small[x][y] + i + j - 1) % 9);
				}
			}
		}
	}

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