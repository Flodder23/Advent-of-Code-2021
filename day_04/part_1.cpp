#include <iostream>
#include <vector>

#include "read_input.cpp"

int part_1(const std::string& filename) {
	std::vector<int> draw; std::vector<Board> board;
	read_input(filename, draw, board);

	for (int i = 0; i < draw.size(); i++) {
		int d = draw[i];
		for (int j = 0; j < board.size(); j++) {
			if (board[j].mark(d)) {
				return d*board[j].score();
			}
		}
	}
	return 0;
}