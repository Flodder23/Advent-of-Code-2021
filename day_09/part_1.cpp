#include <vector>

#include "read_input.cpp"

int part_1(const std::string& filename) {
	std::vector<std::vector<int>> map;
	read_input(filename, map);

	int sum = 0;
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if ((i == 0               || map[i][j] < map[i-1][j]) &&
				(i == map.size()-1    || map[i][j] < map[i+1][j]) &&
				(j == 0               || map[i][j] < map[i][j-1]) &&
				(j == map[i].size()-1 || map[i][j] < map[i][j+1]))
			{
				sum += map[i][j] + 1;
			}
		}
	}

	return sum;
}