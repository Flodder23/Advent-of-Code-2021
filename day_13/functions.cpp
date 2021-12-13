#ifndef FUNCTIONS_CPP
#define FUNCTIONS_CPP

#include <set>

std::set<std::pair<int, int>> do_fold(std::set<std::pair<int, int>>& dots, char a, int pos) {
	std::set<std::pair<int, int>> new_dots;
	std::pair<int, int> new_dot;
	for (const std::pair<int, int>& dot : dots) {
		if (a == 'x' && dot.first > pos) {
			new_dot = {2*pos - dot.first, dot.second};
		} else if (a == 'y' && dot.second > pos) {
			new_dot = {dot.first, 2*pos - dot.second};
		} else {
			new_dot = dot;
		}
		new_dots.insert(new_dot);
	}
	return new_dots;
}

#endif