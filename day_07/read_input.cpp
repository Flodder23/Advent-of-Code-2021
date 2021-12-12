#ifndef READ_INPUT_CPP
#define READ_INPUT_CPP

#include <fstream>
#include <string>
#include <vector>

#include "../general_functions.cpp"

void read_input(const std::string& filename, std::vector<int>& crabs) {
	std::ifstream input(filename);
	std::string in;
	std::getline(input, in);
	std::vector<std::string> crabs_str;
	split_string(in, ',', crabs_str);
	vec_str_to_vec_int(crabs_str, crabs);
}

#endif