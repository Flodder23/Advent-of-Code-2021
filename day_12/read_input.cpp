#ifndef READ_INPUT_CPP
#define READ_INPUT_CPP

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

#include "../general_functions.cpp"

void read_input(const std::string& filename, std::map<std::string, std::set<std::string>>& links) {
	std::ifstream input(filename);
	std::string in;
	while (std::getline(input, in)) {
		std::vector<std::string> link;
		split_string(in, '-', link);
		links[link[0]].insert(link[1]);
		links[link[1]].insert(link[0]);
	}
}

#endif