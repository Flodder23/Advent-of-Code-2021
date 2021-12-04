#include <iostream>
#include <vector>

#include "read_input.cpp"

void part_1() {
	std::vector<int> draw; std::vector<Board> board;
	read_input(draw, board);

	for (int i = 0; i < draw.size(); i++) {
		int d = draw[i];
		for (int j = 0; j < board.size(); j++) {
			if (board[j].mark(d)) {
				std::cout << d*board[j].score();
				return;
			}
		}
	}
}