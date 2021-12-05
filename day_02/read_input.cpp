#ifndef READ_INPUT_CPP
#define READ_INPUT_CPP

#include <fstream>
#include <string>
#include <vector>

void read_input(const std::string& filename, std::vector<std::string>& direction, std::vector<int>& length) {
	std::ifstream input(filename);
	std::string in;
	while (std::getline(input, in)) {
		direction.push_back(in.substr(0, 1));
		length.push_back(std::stoi(in.substr(in.size()-1, 1)));
		// only last character of string since all lengths are one digit long
	}
}

#endif