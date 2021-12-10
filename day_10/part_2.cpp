#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>

#include "read_input.cpp"

typedef long long unsigned bigboi;

bigboi part_2(const std::string& filename) {
	std::vector<std::vector<char>> chunks;
	read_input(filename, chunks);
	std::set<char>  open({'(', '[', '{', '<'});
	std::map<char, char> close({{')', '('}, {']', '['}, {'}', '{'}, {'>', '<'}});
	std::map<char, int> get_score({{')', 3}, {']', 57}, {'}', 1197}, {'>', 25137},
		{'(', 1}, {'[', 2}, {'{', 3}, {'<', 4}});

	std::vector<bigboi> scores;
	for (std::vector<char> chunk : chunks) {
		bool is_incomplete = true;
		std::stack<char> read;
		for (char c : chunk) {
			if (open.find(c) == open.end()) {
				if (read.size() > 0 && read.top() == close[c]) {
					read.pop();
				} else {
					is_incomplete = false;
					break;
				}
			} else {
				read.push(c);
			}
		}
		if (is_incomplete) {
			bigboi score = 0;
			while (read.size() > 0) {
				score *= static_cast<bigboi>(5);
				score += static_cast<bigboi>(get_score[read.top()]);
				read.pop();
			}
			scores.push_back(score);
			std::push_heap(scores.begin(), scores.end());
		}
	}
	std::sort_heap(scores.begin(), scores.end());
	return scores[scores.size()/2];
}