#ifndef READ_INPUT_CPP
#define READ_INPUT_CPP

#include <fstream>
#include <string>
#include <vector>
#include <string>

#include "../general_functions.cpp"

void read_input(const std::string& filename, std::vector<std::vector<std::string>>& examples, std::vector<std::vector<std::string>>& outputs) {
	std::ifstream input(filename);
	std::string in;
	while (std::getline(input, in)) {
		std::vector<std::string> ex, out;
		split_string(in.substr(0, 59), ' ', ex);
		split_string(in.substr(61), ' ', out);
		examples.push_back(ex);
		outputs.push_back(out);
	}
}

#endif