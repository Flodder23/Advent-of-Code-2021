#ifndef READ_INPUT_CPP
#define READ_INPUT_CPP

#include <fstream>
#include <string>
#include <regex>

#include "../general_functions.cpp"

void read_input(const std::string& filename, int& min_x, int& max_x, int& min_y, int& max_y) {
	std::ifstream input(filename);
	std::string in;
	std::getline(input, in);
	std::regex reg("target area: x=(-?\\d+)\\.\\.(-?\\d+), y=(-?\\d+)\\.\\.(-?\\d+)");
	std::smatch match;
	std::regex_match(in, match, reg);
	min_x = std::stoi(match[1]);
	max_x = std::stoi(match[2]);
	min_y = std::stoi(match[3]);
	max_y = std::stoi(match[4]);
}

#endif