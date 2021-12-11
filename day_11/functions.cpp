#ifndef FUNCTIONS_CPP
#define FUNCTIONS_CPP

#include <vector>

void get_adj(int x, int y, int max_x, int max_y, std::vector<std::vector<int>>& adj) {
	int x_min = (x == 0)       ? 0 : x-1;
	int x_max = (x == max_x) ? max_x : x+1;
	int y_min = (y == 0)       ? 0 : y-1;
	int y_max = (y == max_y) ? max_y : y+1;

	for (int i = x_min; i <= x_max; i++) {
		for (int j = y_min; j <= y_max; j++) {
			if (i != x || j != y) {
				adj.push_back({i, j});
			}
		}
	}
}

void increment_octopus(int x, int y, std::vector<std::vector<int>>& octopi, int& total_flashes) {
	if (octopi[x][y] == 9) {
		total_flashes ++;
		octopi[x][y] = -1;
		std::vector<std::vector<int>> adj;
		get_adj(x, y, octopi.size()-1, octopi[x].size()-1, adj);
		for (std::vector<int> coords : adj) {
			increment_octopus(coords[0], coords[1], octopi, total_flashes);
		}
	} else if (octopi[x][y] >= 0) {
		octopi[x][y] ++;
	}
}

#endif