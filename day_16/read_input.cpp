#ifndef READ_INPUT_CPP
#define READ_INPUT_CPP

#include <fstream>
#include <string>
#include <map>

#include "../general_functions.cpp"

std::map<char, std::vector<int>> hex_conv = {
	{'0', {0, 0, 0, 0}},
	{'1', {0, 0, 0, 1}},
	{'2', {0, 0, 1, 0}},
	{'3', {0, 0, 1, 1}},
	{'4', {0, 1, 0, 0}},
	{'5', {0, 1, 0, 1}},
	{'6', {0, 1, 1, 0}},
	{'7', {0, 1, 1, 1}},
	{'8', {1, 0, 0, 0}},
	{'9', {1, 0, 0, 1}},
	{'A', {1, 0, 1, 0}},
	{'B', {1, 0, 1, 1}},
	{'C', {1, 1, 0, 0}},
	{'D', {1, 1, 0, 1}},
	{'E', {1, 1, 1, 0}},
	{'F', {1, 1, 1, 1}},
};

void read_input(const std::string& filename, std::vector<int>& message) {
	std::ifstream input(filename);
	std::string in;
	std::getline(input, in);
	for (const char& c : in) {
		for (const int& i : hex_conv[c]) {
			message.push_back(i);
		}
	}
}

#endif