#ifndef READ_INPUT_CPP
#define READ_INPUT_CPP

#include <vector>
#include <fstream>
#include <string>

void read_input(const std::string& filename, std::vector<int>& parsed) {
	std::ifstream input(filename);
	std::string in;
	while (std::getline(input, in)) {
		parsed.push_back(std::stoi(in));
	}
}

#endif