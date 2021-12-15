#ifndef READ_INPUT_CPP
#define READ_INPUT_CPP

#include <fstream>
#include <string>
#include <vector>

#include "../general_functions.cpp"

void get_adj(int x, int y, int max_x, int max_y, std::vector<std::pair<int, int>>& adj) {
	if (x > 0)     { adj.push_back({x-1, y}); }
	if (x < max_x) { adj.push_back({x+1, y}); }
	if (y > 0)     { adj.push_back({x, y-1}); }
	if (y < max_y) { adj.push_back({x, y+1}); }
}

void read_input(const std::string& filename, std::vector<std::vector<int>>& map) {
	std::ifstream input(filename);
	std::string in;
	while (std::getline(input, in)) {
		map.push_back(std::vector<int>());
		for (const char c : in) {
			map[map.size()-1].push_back(std::atoi(&c));
		}
	}
}

#endif