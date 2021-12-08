#ifndef READ_INPUT_CPP
#define READ_INPUT_CPP

#include <fstream>
#include <string>
#include <vector>
#include <regex>

void read_input(const std::string& filename, std::vector<std::vector<std::vector<int>>>& vents) {
	std::ifstream input(filename);
	std::string in;

	std::regex reg("(\\d+),(\\d+) -> (\\d+),(\\d+)");
	std::smatch match;
	std::vector<int> vent_1;
	std::vector<int> vent_2;
	std::vector<std::vector<int>> vent;
	while (std::getline(input, in)) {
		std::regex_match(in, match, reg);
		vent_1 = {std::stoi(match[1]), std::stoi(match[2])};
		vent_2 = {std::stoi(match[3]), std::stoi(match[4])};
		vent = {vent_1, vent_2};
		vents.push_back(vent);
	}
}

#endif