#include <iostream>
#include <vector>

#include "read_input.cpp"

void part_2() {
	std::vector<int> draw; std::vector<Board> board;
	read_input(draw, board);
	
	std::vector<bool> complete(board.size(), false);
	int c = 0;
	for (int i = 0; i < draw.size(); i++) {
		int d = draw[i];
		for (int j = 0; j < board.size(); j++) {
			if (!complete[j] && board[j].mark(d)) {
				if (c == board.size()-1) {
					std::cout << d*board[j].score();
					return;
				}
				complete[j] = true;
				c++;
			}
		}
	}
}