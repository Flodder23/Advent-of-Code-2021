#ifndef READ_INPUT_CPP
#define READ_INPUT_CPP

#include <fstream>
#include <string>
#include <vector>

void get_adj(int x, int y, int max_x, int max_y, std::vector<std::vector<int>>& adj) {
	if (x > 0)     { adj.push_back({x-1, y}); }
	if (x < max_x) { adj.push_back({x+1, y}); }
	if (y > 0)     { adj.push_back({x, y-1}); }
	if (y < max_y) { adj.push_back({x, y+1}); }
}

void str_vec_to_int_vec(const std::vector<char>& vec_char, std::vector<int>& vec_int) {
	for (char c : vec_char) {
		vec_int.push_back(std::atoi(&c));
	}
}

void str_to_vec_char(const std::string& str, std::vector<char>& vec_char) {
	for (char c : str) {
		vec_char.push_back(c);
	}
}

void read_input(const std::string& filename, std::vector<std::vector<int>>& map) {
	std::ifstream input(filename);
	std::string in;
	while (std::getline(input, in)) {
		std::vector<char> vec_char;
		str_to_vec_char(in, vec_char);
		std::vector<int> vec_int;
		str_vec_to_int_vec(vec_char, vec_int);
		map.push_back(vec_int);
	}
}

#endif