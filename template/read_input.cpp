#ifndef READ_INPUT_CPP
#define READ_INPUT_CPP

#include <fstream>
#include <string>

void read_input(const std::string& filename) {
	std::ifstream input(filename);
	std::string in;
	while (std::getline(input, in)) {
		
	}
}

#endif