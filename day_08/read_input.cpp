#ifndef READ_INPUT_CPP
#define READ_INPUT_CPP

#include <fstream>
#include <string>
#include <vector>
#include <string>

void split_string(const std::string& str, const char& delim, std::vector<std::string>& vec) {
	std::size_t curt = 0, next = 0;
	while (true) {
		next = str.find_first_of(delim, curt);
		if (next == std::string::npos) {
			vec.push_back(str.substr(curt));
			return;
		}
		if (next != curt) {
			vec.push_back(str.substr(curt, next-curt));
		}
		if (next == str.size()-1) { return; }
		curt = next+1;
	}
}

void read_input(const std::string& filename, std::vector<std::vector<std::string>>& examples, std::vector<std::vector<std::string>>& outputs) {
	std::ifstream input(filename);
	std::string in;
	while (std::getline(input, in)) {
		std::vector<std::string> split, ex, out;
		split_string(in, '|', split);
		split_string(split[0], ' ', ex);
		split_string(split[1], ' ', out);
		examples.push_back(ex);
		outputs.push_back(out);
	}
}

#endif