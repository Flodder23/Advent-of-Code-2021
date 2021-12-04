#ifndef BOARD_CPP
#define BOARD_CPP

#include <vector>

class Board {
	std::vector<std::vector<int>> board;
public:
	int nRows, nCols;

	Board() { nRows = 0; nCols = 0; }
	Board(std::vector<std::vector<int>> b) {
		board = b;
		nRows = b.size();
		nCols = b[b.size()-1].size();
	}

	int operator()(int r, int c) const {
		return board[r][c];
	}
	int& operator()(int r, int c) {
		return board[r][c];
	}

	void add_row(const std::vector<int>& row) {
		board.push_back(row);
		nRows ++;
		nCols = row.size();
	}

	bool mark(int num) {
		for (int r = 0; r < nRows; r++) {
			for (int c = 0; c < nCols; c++) {
				if (board[r][c] == num) {
					mark(r, c);
					return check_square(r, c);
				}
			}
		}
		return false;
	}
	void mark(int r, int c) {
		board[r][c] = -1;
	}

	bool check_row(int r) const {
		for(int c = 0; c < board[r].size(); c++) {
			if (board[r][c] != -1) {
				return false;
			}
		}
		return true;
	}
	bool check_col(int c) const {
		for(int r = 0; r < board.size(); r++) {
			if (board[r][c] != -1) {
				return false;
			}
		}
		return true;
	}
	bool check_square(int r, int c) const {
		return (check_row(r) || check_col(c));
	}

	int score() {
		int s = 0;
		for (int r = 0; r < nRows; r++) {
			for (int c = 0; c < nCols; c++) {
				if (board[r][c] != -1) {
					s += board[r][c];
				}
			}
		}
		return s;
	}
};

#endif