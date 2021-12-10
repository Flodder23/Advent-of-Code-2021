#include <vector>
#include <set>
#include <map>
#include <stack>

#include "read_input.cpp"

int part_1(const std::string& filename) {
	std::vector<std::vector<char>> chunks;
	read_input(filename, chunks);
	std::set<char>  open({'(', '[', '{', '<'});
	std::map<char, char> close({{')', '('}, {']', '['}, {'}', '{'}, {'>', '<'}});
	std::map<char, int> get_score({{')', 3}, {']', 57}, {'}', 1197}, {'>', 25137}});

	int score = 0;
	for (std::vector<char> chunk : chunks) {
		std::stack<char> read;
		for (char c : chunk) {
			if (open.find(c) == open.end()) {
				if (read.size() > 0 && read.top() == close[c]) {
					read.pop();
				} else {
					score += get_score[c];
					break;
				}
			} else {
				read.push(c);
			}
		}
	}

	return score;
}