#ifndef READ_INPUT_CPP
#define READ_INPUT_CPP

#include <fstream>
#include <string>
#include <vector>

void vec_char_to_vec_int(const std::vector<char>& vec_char, std::vector<int>& vec_int) {
	for (char c : vec_char) {
		vec_int.push_back(std::atoi(&c));
	}
}

void str_to_vec_char(const std::string& str, std::vector<char>& vec_char) {
	for (char c : str) {
		vec_char.push_back(c);
	}
}

void read_input(const std::string& filename, std::vector<std::vector<int>>& octopi) {
	std::ifstream input(filename);
	std::string in;
	while (std::getline(input, in)) {
		std::vector<char> char_octopi;
		str_to_vec_char(in, char_octopi);
		std::vector<int> int_octopi;
		vec_char_to_vec_int(char_octopi, int_octopi);
		octopi.push_back(int_octopi);
	}
}

#endif