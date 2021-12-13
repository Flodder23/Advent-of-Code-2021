#ifndef READ_INPUT_CPP
#define READ_INPUT_CPP

#include <fstream>
#include <string>
#include <set>

#include "../general_functions.cpp"

void read_input(const std::string& filename, std::set<std::pair<int, int>>& dots, std::vector<std::pair<char, int>>& folds) {
	std::ifstream input(filename);
	std::string in;
	while (std::getline(input, in)) {
		if (in == "") { break; }
		std::vector<std::string> dot_str;
		split_string(in, ',', dot_str);
		dots.insert({std::stoi(dot_str[0]), std::stoi(dot_str[1])});
	}
	while (std::getline(input, in)) {
		std::vector<std::string> fold_str;
		split_string(in, ' ', fold_str);
		std::vector<std::string> fold_s;
		split_string(fold_str[2], '=', fold_s);
		folds.push_back({fold_s[0][0], std::stoi(fold_s[1])});
	}
}

#endif