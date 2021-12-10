#ifndef READ_INPUT_CPP
#define READ_INPUT_CPP

#include <fstream>
#include <string>
#include <vector>

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