#ifndef READ_INPUT_CPP
#define READ_INPUT_CPP

#include <fstream>
#include <string>
#include <vector>

void read_input(std::vector<std::vector<int>>& parsed) {
	std::ifstream input("input.txt");
	std::string in;
	while (std::getline(input, in)) {
		parsed.push_back(std::vector<int>());
		for(int i = 0; i < in.size(); i++) {
			parsed[parsed.size()-1].push_back(std::stoi(in.substr(i, 1)));
		}
	}
}

#endif