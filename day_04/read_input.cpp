#ifndef READ_INPUT_CPP
#define READ_INPUT_CPP

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

#include "board.cpp"

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

void str_vec_to_int_vec(const std::vector<std::string>& str_vec, std::vector<int>& int_vec) {
	for (int i = 0; i < str_vec.size(); i++) {
		int_vec.push_back(std::stoi(str_vec[i]));
	}
}

void read_input(std::vector<int>& draw, std::vector<Board>& board) {
	std::ifstream input("input.txt");
	std::string in;

	std::getline(input, in);
	std::vector<std::string> draw_str;
	split_string(in, ',', draw_str);
	str_vec_to_int_vec(draw_str, draw);

	while (std::getline(input, in)) {
		if (in.size() == 0) {
			board.push_back(Board());
		} else {
			std::vector<std::string> row_str;
			split_string(in, ' ', row_str);
			std::vector<int> row_int;
			str_vec_to_int_vec(row_str, row_int);
			board[board.size()-1].add_row(row_int);
		}
	}
}

#endif