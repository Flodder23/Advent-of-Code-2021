#ifndef READ_INPUT_CPP
#define READ_INPUT_CPP

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

#include "board.cpp"

#include "../general_functions.cpp"

void read_input(const std::string& filename, std::vector<int>& draw, std::vector<Board>& board) {
	std::ifstream input(filename);
	std::string in;

	std::getline(input, in);
	std::vector<std::string> draw_str;
	split_string(in, ',', draw_str);
	vec_str_to_vec_int(draw_str, draw);

	while (std::getline(input, in)) {
		if (in.size() == 0) {
			board.push_back(Board());
		} else {
			std::vector<std::string> row_str;
			split_string(in, ' ', row_str);
			std::vector<int> row_int;
			vec_str_to_vec_int(row_str, row_int);
			board[board.size()-1].add_row(row_int);
		}
	}
}

#endif